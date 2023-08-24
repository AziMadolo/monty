#include "monty.h"

/**
 * subtract_top_two - Subtracts the top two elements of the stack.
 * @stack: Pointer to the stack's top.
 * @line_number: Line number in the Monty bytecode file.
 */
void subtract_top_two(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int result, num_elements;

    temp = *stack;
    num_elements = 0;

    while (temp != NULL)
    {
        num_elements++;
        temp = temp->next;
    }

    if (num_elements < 2)
    {
        fprintf(stderr, "L%d: cannot perform subtraction, stack has too few elements\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    result = temp->next->n - temp->n;
    temp->next->n = result;
    *stack = temp->next;
    free(temp);
}
