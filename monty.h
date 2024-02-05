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

void error1(int errorn, char *file_name, int line_number);
void error1(int errorn, int line_number);
void (*get_op_func(char *s))(stack_t **, unsigned int);
void push_stack(stack_t **ahead, unsigned int vn);
void printall(stack_t **ahead, unsigned int line_number);
void freedlist(stack_t *head);
void printtop(stack_t **ahead, unsigned int line_number);
void removetop(stack_t **ahead, unsigned int line_number);
void swaptwotop(stack_t **ahead, unsigned int line_number);
void addtwotop(stack_t **ahead, unsigned int line_number);
void nop(stack_t **ahead, unsigned int line_number);
void subtopsec(stack_t **ahead, unsigned int line_number);
void div(stack_t **ahead, unsigned int line_number);
void _mul(stack_t **ahead, unsigned int line_number);
void _mod(stack_t **ahead, unsigned int line_number);
void _printchar(stack_t **ahead, unsigned int line_number);
void _printstring(stack_t **ahead, unsigned int line_number);
void _rotate(stack_t **ahead, unsigned int line_number);
void _rotatestack(stack_t **ahead, unsigned int line_number);
void _pushinqueue(stack_t **ahead, unsigned int value);
void readfile(FILE *file);
int _split(char *line, int line_number, int flag);
void _opcodefunc(char *value, char *monty, int line_number, int flag);

#endif
