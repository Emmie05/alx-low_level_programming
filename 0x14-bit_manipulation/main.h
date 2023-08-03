#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* 0. Binary to unsigned int */
unsigned int binary_to_uint(const char *b);

/* 1. Print binary representation */
void print_binary(unsigned long int n);

/* 2. Get the value of a bit at a given index */
int get_bit(unsigned long int n, unsigned int index);

/* 3. Set the value of a bit to 1 at a given index */
int set_bit(unsigned long int *n, unsigned int index);

/* 4. Set the value of a bit to 0 at a given index */
int clear_bit(unsigned long int *n, unsigned int index);

/* 5. Number of bits needed to flip to get from one number to another */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/* 6. Check the endianness */
int get_endianness(void);

/* Helper function used in task 0 */
int _putchar(char c);

#endif /* MAIN_H */

