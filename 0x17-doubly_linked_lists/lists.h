#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

/* Task 0 - Print list */
size_t print_dlistint(const dlistint_t *h);

/* Task 1 - List length */
size_t dlistint_len(const dlistint_t *h);

/* Task 2 - Add node at the beginning */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);

/* Task 3 - Add node at the end */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/* Task 4 - Free list */
void free_dlistint(dlistint_t *head);

/* Task 5 - Get node at index */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/* Task 6 - Sum list */
int sum_dlistint(dlistint_t *head);

/* Task 7 - Insert at index */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);

/* Task 8 - Delete at index */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif
