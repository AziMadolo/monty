#include "monty.h"

/**
 * custom_pchar - prints the character at the top of the stack,
 * followed by a newline
 * @stack_head: pointer to the head of the stack
 * @line_number: current line number
 * Return: void
 */
void custom_pchar(stack_t **stack_head, unsigned int line_number)
{
    stack_t *stack_top = *stack_head;

    if (!stack_top)
    {
        fprintf(stderr, "L%d: Unable to perform pchar - stack is empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    if (stack_top->n > 127 || stack_top->n < 0)
    {
        fprintf(stderr, "L%d: Unable to perform pchar - value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", stack_top->n);
}
