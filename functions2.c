
#include "monty.h"

/**
 * swap - swaps first two values of stack
 * @head: pointer to head
 * @n: unused
 *
 * Return: void
 */

void swap(stack_t **head, __attribute__ ((unused)) unsigned int n)
{
	extern int val;

	stack_t *tmp;
	unsigned int num;

	if (*head == NULL || (*head)->next == NULL)
	{
		val = -6;
	}

	else
	{
		tmp = (*head)->next;
		num = tmp->n;
		tmp->n = (*head)->n;
		(*head)->n = num;
	}
}

/**
 * add - adds top two elements of list, pops first one
 * @head: pointer to head
 * @n: unused
 *
 * Return: void
 */

void add(stack_t **head, __attribute__ ((unused)) unsigned int n)
{
	extern int val;

	stack_t *tmp;
	unsigned int sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		val = -7;
	}
	else
	{
		tmp = (*head)->next;
		sum = (*head)->n + tmp->n;
		pop(head, 0);
		(*head)->n = sum;
	}
}

/**
 * nop - does nothing
 * @head: void
 * @n: void
 *
 * Return: void
 */

void nop(stack_t **head, unsigned int n)
{
	(void)head;
	(void)n;
}