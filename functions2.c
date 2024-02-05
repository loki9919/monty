#include "monty.h"

/**
 * swaptwotop - swaps the top two elements 
 * @ln: line number of the command
 * @ahead: address of the head
 */
void swaptwotop(stack_t **ahead, unsigned int ln)
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
		error(8, NULL, ln);
}
/**
 * addtwotop - swaps the top two elements
 * @ln: line number of the command
 * @ahead: address of the head
 */
void addtwotop(stack_t **ahead, unsigned int ln)
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
		removetop(ahead, ln);
	}
	else
		error(9, NULL, ln);
}
/**
 * nop - doesn’t do anything
 * @ln: line number of the command
 * @ahead: address of the head
 */
void nop(stack_t **ahead, unsigned int ln)
{
	(void)ln;
	(void)ahead;
}
/**
 * subtopsec - subtracts top element from the second top element
 * @ln: line number of the command
 * @ahead: address of the head
 */
void subtopsec(stack_t **ahead, unsigned int ln)
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
		error(10, NULL, ln);
}

/**
 * div - divides second top element
 * @ln: line number of the command
 * @ahead: address of the head
 */
void div(stack_t **ahead, unsigned int ln)
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
			error1(12, ln);
		tmpv = tmp->next->n / tmp->n;
		tmp->next->n = tmpv;
		removetop(ahead, ln);
	}
	else
		error1(11, line_number);
}
