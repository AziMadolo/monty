#include "monty.h"

/**
 * perform_division - Divides the top two elements of the stack.
 * @head_ref: Pointer to the stack's head
 * @line_num: Line number of the operation
 * Return: No explicit return
 */
void perform_division(stack_t **head_ref, unsigned int line_num) {
    stack_t *temp;
    int stack_size = 0, result;

    temp = *head_ref;
    while (temp) {
        temp = temp->next;
        stack_size++;
    }

    if (stack_size < 2) {
        fprintf(stderr, "L%d: Insufficient elements to perform division\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head_ref);
        exit(EXIT_FAILURE);
    }

    temp = *head_ref;
    if (temp->n == 0) {
        fprintf(stderr, "L%d: Division by zero\n", line_num);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head_ref);
        exit(EXIT_FAILURE);
    }

    result = temp->next->n / temp->n;
    temp->next->n = result;
    *head_ref = temp->next;
    free(temp);
}
