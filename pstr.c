#include "monty.h"
/**
 * print_string_from_stack - prints the string from the top of the stack,
 * followed by a newline
 * @stack: pointer to the stack
 * @line_number: line number in the script
 * Return: No return value
 */
void print_string_from_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;

	current_node = *stack;
	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}
