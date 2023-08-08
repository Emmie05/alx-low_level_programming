#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <elf.h>

/**
 * error_exit - Prints an error message and exits with a specific code.
 * @exit_code: The exit code to use.
 * @message: The error message to print.
 */
void error_exit(int exit_code, const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

/**
 * print_magic - Prints the ELF magic bytes.
 * @magic: The ELF magic bytes.
 */
void print_magic(unsigned char *magic)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", magic[i]);
    printf("\n");
}

/**
 * print_header - Prints the ELF header information.
 * @header: The ELF header.
 */
void print_header(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    print_magic(header->e_ident);
    printf("  Class:                             ");
    if (header->e_ident[EI_CLASS] == ELFCLASS32)
        printf("ELF32\n");
    else if (header->e_ident[EI_CLASS] == ELFCLASS64)
        printf("ELF64\n");
    else
        printf("Invalid\n");

    printf("  Data:                              ");
    if (header->e_ident[EI_DATA] == ELFDATA2LSB)
        printf("2's complement, little endian\n");
    else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
        printf("2's complement, big endian\n");
    else
        printf("Invalid\n");

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %d (%s)\n", header->e_type,
           header->e_type == ET_EXEC ? "EXEC (Executable file)" :
           header->e_type == ET_DYN ? "DYN (Shared object file)" :
           header->e_type == ET_REL ? "REL (Relocatable file)" :
           "Unknown");

    printf("  Entry point address:               %#lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
    int fd;
    Elf64_Ehdr header;

    if (argc != 2)
        error_exit(98, "Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_exit(98, "Error: Cannot open file");

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        error_exit(98, "Error: Cannot read file");

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
        error_exit(98, "Error: Not an ELF file");

    print_header(&header);

    close(fd);
    return (0);
}
