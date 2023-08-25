#include "monty.h"

/**
 * execute - Executes the opcode.
 * @content: Line content from the Monty file.
 * @stack: Head of the linked list - stack.
 * @counter: Line counter.
 * @file: Pointer to the Monty file.
 * Return: No return value.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opst[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *op;

    /* Tokenize the content to extract the opcode */
    op = strtok(content, " \n\t");

    /* Ignore lines starting with # */
    if (op && op[0] == '#')
        return (0);

    /* Tokenize the content to extract the argument */
    bus.arg = strtok(NULL, " \n\t");

    /* Iterate through the opcode list to find a match */
    while (opst[i].opcode && op)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            /* Execute the opcode function associated with the opcode */
            opst[i].f(stack, counter);
            return (0);
        }
        i++;
    }

    /* If opcode is not found, print error message and exit */
    if (op && opst[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return (1);
}
