#include "monty.h"

/**
 * main - handles monty program
 * @argc: number of command line arguments
 * @argv: command line argument vector
 *
 * Return: exit success or exit failure
 */

int val = 0;
int main(int argc, char **argv)
{
	FILE *stream;
	char *line = NULL, *arg1, *arg2;
	size_t len = 0;
	ssize_t nread;
	stack_t *head = NULL;
	int count = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		arg1 = strtok(line, " \n");
		arg2 = strtok(NULL, " \n");
		val = verifier(arg1, arg2);
		if (val < 0)
		{
			p_error(count);
			exit_prep(head, line, stream);
			exit(EXIT_FAILURE);
		}
		head = diverter(head, arg1, val);
		if (val < 0)
		{
			p_error(count);
			exit_prep(head, line, stream);
			exit(EXIT_FAILURE);
		}
		count++;
	}
	exit_prep(head, line, stream);
	exit(EXIT_SUCCESS);
}