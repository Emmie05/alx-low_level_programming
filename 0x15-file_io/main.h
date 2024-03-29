#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/* 0-read_textfile.c */
ssize_t read_textfile(const char *filename, size_t letters);

/* 1-create_file.c */
int create_file(const char *filename, char *text_content);

/* 2-append_text_to_file.c */
int append_text_to_file(const char *filename, char *text_content);

/* 3-cp.c */
void error_exit(int exit_code, const char *message);
int main(int argc, char **argv);

/* 100-elf_header.c */
void print_magic(unsigned char *magic);
const char *get_osabi_name(unsigned char osabi);
const char *get_type_name(unsigned int type);
void print_header(Elf64_Ehdr *header);
int main(int argc, char **argv);

#endif
