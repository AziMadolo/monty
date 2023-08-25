#include "monty.h"
/**
 * f_pall - Prints all elements in the stack
 * @head: Pointer to the stack's head
 * @counter: Unused counter parameter
 * Return: No return value
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    if (h == NULL)
        return;

    /* Traverse the stack and print each element */
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}
