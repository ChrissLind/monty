#include "monty.h"

int main (int argc, char **argv)
{
    FILE *stream; 
    char *line = NULL;
    size_t len = 0;
    stack_t *tmp;
    ssize_t nread;
    stack_t *head = NULL;
    char *arg1, *arg2;
    int val;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit (EXIT_FAILURE);
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
            if (arg2 != NULL)
            {
                val = atoi(arg2);
                head = diverter(head, arg1, val);
            }
            else
            {
                head = diverter(head, arg1, 1);
            }
    }

    free(line);
    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    fclose(stream);
    exit(EXIT_SUCCESS);
}