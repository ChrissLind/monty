#include "monty.h"

stack_t *diverter(stack_t *head, char *arg1, int arg2)
{
    int idx;
    instruction_t diverter[] = {
        {"push", push},
        {"pall", pall},
    };

    for (idx = 0; idx < 2; idx++)
    {
        if (strcmp(arg1, diverter[idx].opcode) == 0)
        {
            diverter[idx].f(&head, arg2);
        }
    }
    return (head);
}