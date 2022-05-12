#include "monty.h"

void push(stack_t **head, unsigned int n)
{
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        /*return (NULL);*/
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