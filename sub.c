#include "monty.h"

/**
 * f_sub - Subtracts the top element of the stack from the second top element
 * @head: Pointer to the stack's head
 * @counter: Line number
 *
 * Return: No return value
 */
void f_sub(stack_t **head, unsigned int counter)
{
    stack_t *aux;
    int sus, nodes;

    aux = *head;

    /* Count the number of nodes in the stack */
    for (nodes = 0; aux != NULL; nodes++)
        aux = aux->next;

    /* Check if there are at least 2 nodes for subtraction */
    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = *head;
    sus = aux->next->n - aux->n;
    aux->next->n = sus;
    *head = aux->next;
    free(aux);
}
