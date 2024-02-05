#include "monty.h"

/**
 * push_stack - pushe to the stack.
 * @vn: value to add to the node
 * @ahead: address head
 */
void push_stack(stack_t **ahead, unsigned int vn)
{
	stack_t *newnode;
	stack_t *cur = *ahead;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		error_function(4, NULL, value);
	newnode->n = vn;
	newnode->next = *ahead;
	newnode->prev = NULL;
	if (cur != NULL)
		cur->prev = newnode;
	head = newnode;
}
/**
 * printall - pushe to the stack
 * @ln: line number
 * @actual_head: address head
 */
void printall(stack_t **ahead, unsigned int line_number)
{
	(void)ln;
	stack_t *tmp;

	if (ahead != NULL)
	{
		tmp = *ahead;
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
/**
 * freedlist - free double linked list
 * @head: address of the head of list
 */
void freedlist(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			freedlist(head->next);
		free(head);
	}
}
/**
 * printtop - prints top of stack
 * @ahead: head of the dlist
 * @ln: line number of the command
 */

void printtop(stack_t **ahead, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;

	tmp = *ahead;
	if (*ahead != NULL)
		printf("%i\n", tmp->n);
	else
		error1(6, NULL, line_number);
}
/**
 * removetop - delete the top in the stack
 * @actual_head: pointer to head
 * @ln: line number of command
 */
void removetop(stack_t **ahead, unsigned int line_number)
{
	stack_t *tmp, *tmp1;

	tmp = *ahead;
	if (tmp == NULL)
		error_function(7, NULL, line_number);
	tmp1 = *ahead;
	*ahead = tmp->next;
	tmp = tmp->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	free(tmp1);
}
