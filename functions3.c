#include "monty.h"

/**
 * _mul -  multiplies second top element
 * @ln: line number of the command
 * @ahead: address of the head
 */
void _mul(stack_t **ahead, unsigned int line_number)
{
	stack_t *tmp = *ahead;
	int counter = 0, tmpv = 0;

	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (counter >= 2)
	{
		tmp = *ahead;
		tmpv = tmp->next->n * tmp->n;
		tmp->next->n = tmpv;
		removetop(ahead, line_number);
	}
	else
		error1(13, line_number);
}
/**
 * _mod - compute rest div second top element
 * @ln: line number of the command
 * @ahead: address of the head
 */
void _mod(stack_t **ahead, unsigned int line_number)
{
	stack_t *tmp = *ahead;
	int counter = 0, tmpv = 0;

	while (tmp)
	{
		tmp = tmp->next;
		counter++;
	}
	if (counter >= 2)
	{
		tmp = *ahead;
		if (tmp->n == 0)
			error1(12, line_number);
		tmpv = tmp->next->n % tmp->n;
		tmp->next->n = tmpv;
		removetop(ahead, line_number);
	}
	else
		error1(14, line_number);
}
/**
 * _printchar -  prints the char
 * @ln: line number of the command
 * @ahead: head of the dlist
 */
void _printchar(stack_t **ahead, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *ahead;
	if (*ahead != NULL)
		if (tmp->n >= 32 && tmp->n <= 126)
			printf("%c\n", tmp->n);
		else
			error1(16, line_number);
	else
		error1(15, line_number);
}
/**
 * _printstring - prints the string starting
 * @ahead: head of the dlist
 * @ln: line number of the command
 */
void _printstring(stack_t **ahead, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;

	tmp = *ahead;
	if (tmp == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n == 0)
			break;
		if (tmp->n < 32 || tmp->n > 126)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * _rotate - rotates the stack to the top
 * @ahead: head of the dlist
 * @ln: line number of the command
 */
void _rotate(stack_t **ahead, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;
	int counter = 0, tmpv = 0;

	tmp = *ahead;
	while (tmp)
	{
		tmp = tmp->next;
		counter++;
	}
	tmp = *ahead;
	if (counter > 1)
	{
		tmpv = tmp->n;
		while (tmp->next)
		{
			tmp->n = tmp->next->n;
			tmp = tmp->next;
		}
		tmp->n = tmpv;
	}
}
