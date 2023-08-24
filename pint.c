#include "monty.h"
/**
 * print_top - prints the top element
 * @stack_head: pointer to the stack's head
 * @line_number: current line number
 * Return: void
*/
void print_top(stack_t **stack_head, unsigned int line_number)
{
    if (*stack_head == NULL)
    {
        fprintf(stderr, "L%u: Unable to print, the stack is empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack_head)->n);
}
