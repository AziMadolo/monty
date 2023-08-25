#include "monty.h"
/**
 * f_div - Divides the second element by the top element of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number being executed
 * Return: No return value
*/
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    /* Count the number of elements in the stack */
    while (h)
    {
        h = h->next;
        len++;
    }
    /* Check if there are at least two elements in the stack */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    /* Check for division by zero */
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    /* Perform the division and update the stack */
    aux = h->next->n / h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}
