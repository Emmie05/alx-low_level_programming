#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUF_SIZE 64

/**
 * print_error - Prints an error message and exits with failure
 * @msg: The error message to print
 */
void print_error(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @filename: The name of the ELF file
 */
void print_elf_header(const char *filename)
{
	int fd, bytes_read;
	Elf32_Ehdr header32;
	Elf64_Ehdr header64;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	bytes_read = read(fd, &header32, sizeof(header32));
	if (bytes_read == -1)
		print_error("Error: Cannot read file");

	lseek(fd, 0, SEEK_SET);
	bytes_read = read(fd, &header64, sizeof(header64));
	if (bytes_read == -1)
		print_error("Error: Cannot read file");

	close(fd);

	if (header32.e_ident[EI_MAG0] != ELFMAG0 ||
	    header32.e_ident[EI_MAG1] != ELFMAG1 ||
	    header32.e_ident[EI_MAG2] != ELFMAG2 ||
	    header32.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i= 0; i < EI_NIDENT; i++)
		printf("%02x%c", header32.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	if (header32.e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("  Class:                             ELF32\n");
		printf("  Data:                              2's complement, %s endian\n",
		       header32.e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
		printf("  Version:                           %d (current)\n", header32.e_ident[EI_VERSION]);
		printf("  OS/ABI:                            %s\n", get_osabi_name(header32.e_ident[EI_OSABI]));
		printf("  ABI Version:                       %d\n", header32.e_ident[EI_ABIVERSION]);
		printf("  Type:                              %s\n", get_type_name(header32.e_type));
		printf("  Entry point address:               0x%x\n", header32.e_entry);
	}
	else if (header32.e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("  Class:                             ELF64\n");
		printf("  Data:                              2's complement, %s endian\n",
		       header64.e_ident[EI_DATA] == ELFDATA2LSB ? "little" : "big");
		printf("  Version:                           %d (current)\n", header64.e_ident[EI_VERSION]);
		printf("  OS/ABI:                            %s\n", get_osabi_name(header64.e_ident[EI_OSABI]));
		printf("  ABI Version:                       %d\n", header64.e_ident[EI_ABIVERSION]);
		printf("  Type:                              %s\n", get_type_name(header64.e_type));
		printf("  Entry point address:               0x%lx\n", header64.e_entry);
	}
}

/**
 * get_osabi_name - Gets the name of the OS/ABI
 * @osabi: The OS/ABI identifier
 *
 * Return: The name of the OS/ABI
 */
const char *get_osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
	case ELFOSABI_SYSV:
		return "UNIX - System V";
	case ELFOSABI_HPUX:
		return "HP-UX";
	case ELFOSABI_NETBSD:
		return "NetBSD";
	case ELFOSABI_LINUX:
		return "Linux";
	case ELFOSABI_SOLARIS:
		return "Solaris";
	case ELFOSABI_IRIX:
		return "IRIX";
	case ELFOSABI_FREEBSD:
		return "FreeBSD";
	case ELFOSABI_TRU64:
		return "TRU64 UNIX";
	case ELFOSABI_ARM:
		return "ARM architecture";
	case ELFOSABI_STANDALONE:
		return "Standalone (embedded) application";
	default:
		return "<unknown>";
	}
}

/**
 * get_type_name - Gets the name of the ELF file type
 * @type: The ELF file type identifier
 *
 * Return: The name of the ELF file type
 */
const char *get_type_name(unsigned int type)
{
	switch (type)
	{
	case ET_NONE:
		return "None";
	case ET_REL:
		return "REL (Relocatable file)";
	case ET_EXEC:
		return "EXEC (Executable file)";
	case ET_DYN:
		return "DYN (Shared object file)";
	case ET_CORE:
		return "CORE (Core file)";
	default:
		return "<unknown>";
	}
}

/**
 * main - Displays the information contained in the ELF header of a file
 * @argc: The number of arguments
 * @argv: The array of arguments
 *
 * Return: 0 on success, or an error code on failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (97);
	}

	print_elf_header(argv[1]);

	return (0);
}
