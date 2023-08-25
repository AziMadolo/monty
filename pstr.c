#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack as characters.
 *         - Stops when encountering a non-printable character or end of stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number where the function is called.
 * Return: No return value.
 */
void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    while (h)
    {
        if (h->n > 127 || h->n <= 0) /* Stop if non-printable or negative value */
        {
            break;
        }
        printf("%c", h->n); /* Print the character value */
        h = h->next;
    }
    printf("\n"); /* Print a newline after printing the characters */
}
