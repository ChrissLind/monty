#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void push(stack_t **head, unsigned int n);
void pall(stack_t **head, __attribute__((unused)) unsigned int n);
stack_t *diverter(stack_t *head, char *arg1, int arg2);
int verifier(char *arg1, char *arg2);
void exit_prep(stack_t *head, char *line, FILE *stream);
void p_error(int count, char *arg);
void pint(stack_t **head, __attribute__ ((unused)) unsigned int n);
void pop(stack_t **head, __attribute__ ((unused)) unsigned int n);
void swap(stack_t **head, __attribute__ ((unused)) unsigned int n);
void add(stack_t **head, __attribute__ ((unused)) unsigned int n);
void nop(stack_t **head, unsigned int n);

#endif