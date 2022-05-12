#include "monty.h"

/**
 * verifier - verifies if instruction is valid
 * @arg1: instruction to verify
 * @arg2: data if push
 *
 * Return: 0 if valid
 */

int verifier(char *arg1, char *arg2)
{
	int idx;
	int value;
	char buffer[100];
	char *array[] = {
		"push",
		"pall",
		"pint",
		"pop",
		"swap",
		"add",
		"nop"};

	for (idx = 0; idx < 7; idx++)
	{
		if (strcmp(arg1, array[idx]) == 0)
		{
			if (strcmp(arg1, "push") == 0)
			{
				if (arg2 == NULL)
				{
					return (-1);
				}
				value = atoi(arg2);
				sprintf(buffer, "%d", value);
				if (strcmp(buffer, arg2) == 0)
				{
					return (value);
				}
				else
				{
					return (-1);
				}
			}
			return (0);
		}
	}
	return (-2);
}