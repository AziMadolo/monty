#include "monty.h"

/**
 * rotate_to_top - Rotates the stack, moving the top element to the bottom.
 * @head: Pointer to the head of the stack.
 * @counter: Line number in the Monty bytecode file.
 */
void rotate_to_top(stack_t **head, unsigned int counter)
{
    stack_t *tmp = *head, *new_top;

    if (*head == NULL || (*head)->next == NULL)
    {
        /* Not enough elements to rotate */
        return;
    }

    new_top = (*head)->next;
    new_top->prev = NULL;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;

    *head = new_top;
}
