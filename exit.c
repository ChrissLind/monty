#include "monty.h"

/**
 * exit_prep - frees list
 * @head: pointer to head node
 * @line: file line
 * @stream: file descriptor
 *
 * Return: void
 */

void exit_prep(stack_t *head, char *line, FILE *stream)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	free(line);
	fclose(stream);
}