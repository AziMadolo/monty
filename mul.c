#include "monty.h"

/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the script
 * 
 * Description: This function multiplies the values of the top two elements
 *              of the stack. The result is stored in the second element,
 *              and the first element is removed from the stack.
 *              If the stack doesn't have at least two elements, an error
 *              message is printed, and the program exits with failure.
 */
void f_mul(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int len = 0, aux;

    h = *head;
    while (h)
    {
        h = h->next;
        len++;
    }
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    aux = h->next->n * h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}
