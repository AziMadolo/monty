#include "monty.h"
/**
 * print_stack - displays the contents of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number (not used here)
 * Return: No return value
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;

    current = *stack;
    if (current == NULL)
        return;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
