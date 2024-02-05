#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

void read_file(FILE *file);
void error_function(int error_number, char *file_name, int line_number);
int split_string(char *lineptr, int line_number, int flag);
void _opcode_funct(char *value, char *opcode, int line_number, int flag);
void _push_to_stack(stack_t **new_node, unsigned int value);
void _print_all_stack(stack_t **actual_head, unsigned int line_number);
void free_dlistint(stack_t *head);
void _print_top_stack(stack_t **actual_head, unsigned int line_number);
void _remove_top_stack(stack_t **actual_head, unsigned int line_number);
void _swap_two_top_stack(stack_t **actual_head, unsigned int line_number);
void _add_two_top_stack(stack_t **actual_head, unsigned int line_number);
void _nop_does_anything(stack_t **actual_head, unsigned int line_number);
void (*get_op_func(char *s))(stack_t **, unsigned int);
void _sub_top_second_stack(stack_t **actual_head, unsigned int line_number);
void _div_second_top_stack(stack_t **actual_head, unsigned int line_number);
void error_funct_2(int error_number, int line_number);
void _mul_second_top_stack(stack_t **actual_head, unsigned int line_number);
void _mod_second_top_stack(stack_t **actual_head, unsigned int line_number);
void _print_char_top_stack(stack_t **actual_head, unsigned int line_number);
void _print_string_top_stack(stack_t **actual_head, unsigned int line_number);
void _rotate_stack_top(stack_t **actual_head, unsigned int line_number);
void _rotate_stack_bottom(stack_t **actual_head, unsigned int line_number);
void _push_in_queue(stack_t **actual_head, unsigned int value);

#endif
