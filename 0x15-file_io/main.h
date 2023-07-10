#ifndef MAIN_H
#define MAIN_H

#include <elf.h>
#include <stddef.h>

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

int append_text_to_file(const char *filename, char *text_content);

int main(int argc, char **argv);

void print_error(const char *message);
void print_elf_header(const Elf64_Ehdr *header);
int read_elf_header(const char *filename, Elf64_Ehdr *header);

#endif
