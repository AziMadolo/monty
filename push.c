#include "monty.h"

/**
 * custom_push - Adds an element to the stack
 * @head: Pointer to the stack's top
 * @counter: Line number in the script
 * Return: No explicit return
 */
void custom_push(stack_t **head, unsigned int counter)
{
    int num, idx = 0, invalid = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            idx++;
        for (; bus.arg[idx] != '\0'; idx++)
        {
            if (bus.arg[idx] > '9' || bus.arg[idx] < '0')
                invalid = 1;
        }
        if (invalid == 1)
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
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    num = atoi(bus.arg);

    if (bus.lifi == 0)
    {
        push_stack(head, num);
    }
    else
    {
        enqueue_stack(head, num);
    }
}
