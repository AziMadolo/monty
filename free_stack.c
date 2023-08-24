#include "monty.h"
/**
* release_memory - deallocates a doubly linked list
* @start: starting node of the stack
*/
void release_memory(stack_t *start)
{
	stack_t *temp;

	temp = start;
	while (start)
	{
		temp = start->next;
		free(start);
		start = temp;
	}
}
