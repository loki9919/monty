#include "monty.h"

/**
 * swaptwotop - swaps the top two elements 
 * @ln: line number of the command
 * @ahead: address of the head
 */
void swaptwotop(stack_t **ahead, unsigned int line_number)
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
		tmpv = tmp->n;
		tmp->n = tmp->next->n;
		tmp->next->n = tmpv;
	}
	else
		error(8, NULL, line_number);
}
/**
 * addtwotop - swaps the top two elements
 * @ln: line number of the command
 * @ahead: address of the head
 */
void addtwotop(stack_t **ahead, unsigned int line_number)
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
		tmpv = tmp->n + tmp->next->n;
		tmp->next->n = tmpv;
		removetop(ahead, line_number);
	}
	else
		error(9, NULL, line_number);
}
/**
 * _nop - doesn’t do anything
 * @ln: line number of the command
 * @ahead: address of the head
 */
void _nop(stack_t **ahead, unsigned int line_number)
{
	(void)line_number;
	(void)ahead;
}
/**
 * _sub - subtracts top element from the second top element
 * @ln: line number of the command
 * @ahead: address of the head
 */
void _sub(stack_t **ahead, unsigned int line_number)
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
		tmpv = tmp->next->n - tmp->n;
		tmp->next->n = tmpv;
		removetop(ahead, ln);
	}
	else
		error(10, NULL, line_number);
}
/**
 * _div - divides second top element
 * @ln: line number of the command
 * @ahead: address of the head
 */
void _div(stack_t **ahead, unsigned int line_number)
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
		tmpv = tmp->next->n / tmp->n;
		tmp->next->n = tmpv;
		removetop(ahead, ln);
	}
	else
		error1(11, line_number);
}
