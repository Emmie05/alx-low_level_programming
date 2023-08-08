#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_exit - Print an error message and exit with a specified code.
 * @exit_code: The exit code.
 * @message: The error message to print.
 */
void error_exit(int exit_code, const char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(exit_code);
}

/**
 * print_magic - Prints the magic bytes of an ELF header.
 * @magic: A pointer to the magic bytes.
 */
void print_magic(unsigned char *magic)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%2.2x%c", magic[i], i == EI_NIDENT - 1 ? '\n' : ' ');
}

/**
 * get_osabi_name - Returns the name of the OS/ABI.
 * @osabi: The OS/ABI identifier.
 *
 * Return: The name of the OS/ABI.
 */
const char *get_osabi_name(unsigned char osabi)
{
    switch (osabi)
    {
        case ELFOSABI_SYSV:         return "UNIX - System V";
        case ELFOSABI_HPUX:         return "HP-UX";
        case ELFOSABI_NETBSD:       return "NetBSD";
        case ELFOSABI_LINUX:        return "Linux";
        case ELFOSABI_SOLARIS:      return "Solaris";
        case ELFOSABI_IRIX:         return "IRIX";
        case ELFOSABI_FREEBSD:      return "FreeBSD";
        case ELFOSABI_TRU64:        return "TRU64 UNIX";
        case ELFOSABI_ARM:          return "ARM architecture";
        case ELFOSABI_STANDALONE:   return "Standalone (embedded) application";
        default:                    return "<unknown>";
    }
}

/**
 * get_type_name - Returns the name of the ELF type.
 * @type: The ELF type.
 *
 * Return: The name of the ELF type.
 */
const char *get_type_name(unsigned int type)
{
    switch (type)
    {
        case ET_NONE:       return "NONE (No file type)";
        case ET_REL:        return "REL (Relocatable file)";
        case ET_EXEC:       return "EXEC (Executable file)";
        case ET_DYN:        return "DYN (Shared object file)";
        case ET_CORE:       return "CORE (Core file)";
        default:            return "<unknown>";
    }
}

/**
 * print_header - Displays information contained in the ELF header.
 * @header: A pointer to the ELF header structure.
 */
void print_header(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", get_osabi_name(header->e_ident[EI_OSABI]));
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", get_type_name(header->e_type));
    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char **argv)
{
    int fd;
    ssize_t bytes_read;
    Elf64_Ehdr header;

    if (argc != 2)
        error_exit(98, "Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_exit(98, "Error: Can't read from file");

    bytes_read = read(fd, &header, sizeof(header));
    if (bytes_read != sizeof(header))
    {
        close(fd);
        error_exit(98, "Error: Can't read from file");
    }

    print_header(&header);
    close(fd);
    return (0);
}
