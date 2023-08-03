#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

/* Task 0 - Binary to Unsigned Int */
unsigned int binary_to_uint(const char *b);

/* Task 1 - Print Binary */
void print_binary(unsigned long int n);

/* Task 2 - Get Bit */
int get_bit(unsigned long int n, unsigned int index);

/* Task 3 - Set Bit */
int set_bit(unsigned long int *n, unsigned int index);

/* Task 4 - Clear Bit */
int clear_bit(unsigned long int *n, unsigned int index);

/* Task 5 - Flip Bits */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/* Task 6 - Endianness */
int get_endianness(void);

/* Helper function used in task 0 */
int _putchar(char c);

#endif
