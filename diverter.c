#include "monty.h"

/**
 * diverter - calls appropiate function
 * @head: pointer to head node
 * @arg1: opcode
 * @arg2: data to enter node when push
 *
 * Return: pointer to heda node
 */

stack_t *diverter(stack_t *head, char *arg1, int arg2)
{
	int idx;
	instruction_t diverter[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
	};

	for (idx = 0; idx < 3; idx++)
	{
		if (strcmp(arg1, diverter[idx].opcode) == 0)
		{
			diverter[idx].f(&head, arg2);
		}
	}
	return (head);
}