#include "monty.h"
/**
 * custom_swap - swaps the values of the top two elements in the stack.
 * @stack_head: pointer to the head of the stack
 * @line_number: current line number
 * Return: void
*/
void custom_swap(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current;
	int stack_size = 0, temp_value;

	current = *stack_head;
	while (current)
	{
		current = current->next;
		stack_size++;
	}
	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: Unable to perform swap, stack has insufficient elements\n", line_number);
		fclose(custom_file.file);
		free(custom_file.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current = *stack_head;
	temp_value = current->n;
	current->n = current->next->n;
	current->next->n = temp_value;

}
