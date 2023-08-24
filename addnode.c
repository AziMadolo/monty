#include "monty.h"

/**
 * addNode - Add a node to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: Value to be stored in the new node
 *
 * Return: No return value
 */
void addNode(stack_t **head, int n)
{
    stack_t *newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    newNode->n = n;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    *head = newNode;
}
