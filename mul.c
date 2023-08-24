#include "monty.h"
/**
 * multiply_top_two - multiplies the top two elements of the stack.
 * @stk_head: pointer to the stack head
 * @line_num: line number in the file
 * Return: no return
*/
void multiply_top_two(stack_t **stk_head, unsigned int line_num)
{
	stack_t *stk_ptr;
	int stack_length = 0, result;

	stk_ptr = *stk_head;
	while (stk_ptr)
	{
		stk_ptr = stk_ptr->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: Unable to perform multiplication, insufficient stack elements\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stk_head);
		exit(EXIT_FAILURE);
	}
	stk_ptr = *stk_head;
	result = stk_ptr->next->n * stk_ptr->n;
	stk_ptr->next->n = result;
	*stk_head = stk_ptr->next;
	free(stk_ptr);
}
