#include "monty.h"

/**
 * custom_mod - Calculate the remainder of the division of the second top element
 *              of the stack by the top element of the stack.
 * @stk_head: Pointer to the head of the stack.
 * @line_num: Line number in the Monty file being processed.
 */
void custom_mod(stack_t **stk_head, unsigned int line_num)
{
    stack_t *current;
    int stack_len = 0, temp_value;

    current = *stk_head;
    while (current)
    {
        current = current->next;
        stack_len++;
    }

    if (stack_len < 2)
    {
        fprintf(stderr, "L%d: Unable to perform mod, stack is too short\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stk_head);
        exit(EXIT_FAILURE);
    }

    current = *stk_head;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: Division by zero\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stk_head);
        exit(EXIT_FAILURE);
    }

    temp_value = current->next->n % current->n;
    current->next->n = temp_value;
    *stk_head = current->next;
    free(current);
}
