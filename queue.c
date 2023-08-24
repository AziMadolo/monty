#include "monty.h"

/**
 * enqueue_operation - Marks the stack as a queue (not implemented here)
 * @stack: Pointer to the stack
 * @line_number: Line number in the script
 */
void enqueue_operation(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    bus.lifi = 1;  // Emulating setting queue mode
}

/**
 * enqueue_value - Adds a new node to the end of the stack (queue mode)
 * @stack: Pointer to the stack
 * @value: Value to be added
 */
void enqueue_value(stack_t **stack, int value)
{
    stack_t *new_node, *current;

    current = *stack;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current->next = new_node;
        new_node->prev = current;
    }
}
