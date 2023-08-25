#include "monty.h"
/**
  * f_rotl - Rotates the stack to the top
  * @head: Pointer to the stack's head
  * @counter: Line number (unused)
  * Return: No return value
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *aux;

	/* Check if the stack is empty or has only one element */
	if (*head == NULL || (*head)->next == NULL)
	{
		return; /* Nothing to rotate */
	}
	aux = (*head)->next; /* Store the second element in aux */
	aux->prev = NULL; /* Detach the second element from the first */

	/* Traverse to the last node */
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	/* Perform the rotation */
	tmp->next = *head; /* Make the last node point to the old head */
	(*head)->next = NULL; /* Detach the old head from the new head */
	(*head)->prev = tmp; /* Set the old head's previous pointer */

	(*head) = aux; /* Update the head to point to the new second element */
}
