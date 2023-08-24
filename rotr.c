#include "monty.h"
/**
  * rotateStackToBottom - Rotate the stack elements to the bottom
  * @head: Pointer to the stack's head
  * @counter: Line number
  * Return: No return value
 */
void rotateStackToBottom(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *last;

    last = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (last->next)
    {
        last = last->next;
    }
    last->next = *head;
    last->prev->next = NULL;
    last->prev = NULL;
    (*head)->prev = last;
    (*head) = last;
}
