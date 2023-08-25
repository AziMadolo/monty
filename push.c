#include "monty.h"

/**
 * f_push - Function to add a node to the stack
 * @head: Pointer to the stack's head
 * @counter: Line number in the input file
 * Description: This function adds a new node containing a given integer
 *              to the top of the stack or queue, depending on 'bus.lifi'.
 *              If the argument is not a valid integer, it exits with an error.
 *              If no argument is provided, it exits with an error.
 * Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0, flag = 0;

    /* Check if there is an argument provided*/
    if (bus.arg)
    {
        /* Check for negative number */
        if (bus.arg[0] == '-')
            j++;

        /* Check if the argument is a valid integer */
        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > 57 || bus.arg[j] < 48)
                flag = 1;
        }

        /* If argument is not a valid integer, exit with an error */
        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* If no argument is provided, exit with an error */
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Convert argument to integer */
    n = atoi(bus.arg);

    /* Add node to the stack or queue based on 'bus.lifi' */
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}
