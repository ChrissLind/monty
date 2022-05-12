#include "monty.h"

/**
 * push - adds new node at the beginning
 * @head: pointer to head node
 * @n: data to enter in node
 *
 * Return: void
 */

void push(stack_t **head, unsigned int n)
{
	stack_t *new;
	extern int val;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		val = -3;
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
	if (new == NULL)
	{
		/*return (NULL);*/
	}

}

/**
 * pall - prints all nodes
 * @head: pointer to heda node
 * @n: unused
 *
 * Return: void
 */

void pall(stack_t **head, __attribute__((unused)) unsigned int n)
{
	int count;
	stack_t *tmp = *head;

	if (head == NULL)
	{
		/*return ('\0');*/
	}

	for (count = 0; tmp != NULL; count++)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints value of first node
 * @head: points to head node
 * @n: unused
 *
 * Return: void
 */

void pint(stack_t **head, __attribute__ ((unused)) unsigned int n)
{
	extern int val;

	if (*head == NULL)
	{
		val = -4;
	}
	else
	{
		printf("%d\n", (*head)->n);
	}

}

/**
 * pop - deletes first node of stack
 * @head: pointer to head node
 * @n: unused
 *
 * Return: void
 */

void pop(stack_t **head, __attribute__ ((unused)) unsigned int n)
{
	extern int val;
	stack_t *tmp = *head;

	if (*head == NULL)
	{
		val = -5;
	}
	else
	{
		*head = (*head)->next;
		free(tmp);
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}
}