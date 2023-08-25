#include "monty.h"

/**
 * f_mod - Computes the rest of the division of the second
 *         top element of the stack by the top element of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_mod(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    /* Calculate the length of the stack */
    while (h)
    {
        h = h->next;
        len++;
    }

    /* Check if there are at least 2 elements in the stack */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    h = *head;
    /* Check if division by zero is attempted */
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Perform the modulo operation */
    aux = h->next->n % h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}
