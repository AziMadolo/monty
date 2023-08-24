#include "monty.h"

/**
 * custom_add - Function to add the top two elements of the stack.
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void custom_add(stack_t **head, unsigned int counter)
{
    stack_t *stack_ptr;
    int stack_len = 0, result;

    stack_ptr = *head;
    while (stack_ptr)
    {
        stack_ptr = stack_ptr->next;
        stack_len++;
    }

    if (stack_len < 2)
    {
        fprintf(stderr, "L%d: Insufficient elements for addition\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    stack_ptr = *head;
    result = stack_ptr->n + stack_ptr->next->n;
    stack_ptr->next->n = result;
    *head = stack_ptr->next;
    free(stack_ptr);
}
