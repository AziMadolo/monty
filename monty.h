#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void custom_add(stack_t **head, unsigned int counter);
int execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file);
int main(int argc, char *argv[]);
void multiply_top_two(stack_t **stk_head, unsigned int line_num);
void print_stack(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack_head, unsigned int line_number);
void print_string_from_stack(stack_t **stack, unsigned int line_number);
void enqueue_value(stack_t **stack, int value);
void rotate_to_top(stack_t **head, unsigned int counter);
void customStackFunction(stack_t **stack, unsigned int lineNum);
void custom_swap(stack_t **stack_head, unsigned int line_number);
void addNode(stack_t **head, int n);
void perform_division(stack_t **head_ref, unsigned int line_num);
void release_memory(stack_t *start);
void custom_mod(stack_t **stk_head, unsigned int line_num);
void custom_nop(stack_t **head, unsigned int counter);
void custom_pchar(stack_t **stack_head, unsigned int line_number);
void custom_pop(stack_t **stack_head, unsigned int line_num);
void custom_push(stack_t **head, unsigned int counter);
void rotateStackToBottom(stack_t **head, __attribute__((unused)) unsigned int counter);
void subtract_top_two(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
