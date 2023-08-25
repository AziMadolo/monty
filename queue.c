#include "monty.h"

/**
 * f_queue - Sets the queue mode flag
 * @head: Pointer to the head of the stack
 * @counter: Line number
 * Return: No return value
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1; /* Set the queue mode flag */
}

/**
 * addqueue - Adds a node to the tail of the stack (queue mode)
 * @n: New value to be added
 * @head: Pointer to the head of the stack
 * Return: No return value
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *aux;

    aux = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n"); /* Error message for memory allocation failure */
    }
    new_node->n = n;
    new_node->next = NULL;
    if (aux)
    {
        while (aux->next)
            aux = aux->next;
    }
    if (!aux)
    {
        *head = new_node; /* Set new node as the head */
        new_node->prev = NULL;
    }
    else
    {
        aux->next = new_node; /* Add new node to the end of the stack */
        new_node->prev = aux;
    }
}

