#include "monty.h"

/**
 * custom_pop - Removes the top element from the stack
 * @stack_head: Pointer to the stack's head
 * @line_num: Line number in the Monty file
 * Return: No return value
 */
void custom_pop(stack_t **stack_head, unsigned int line_num)
{
    stack_t *temp;

    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%d: unable to pop from an empty stack\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    temp = *stack_head;
    *stack_head = temp->next;
    free(temp);
}
