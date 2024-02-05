#include "monty.h"

/**
 * _rotatestack - rotates the stack to the bottom
 * @ahead: head of the dlist
 * @ln: line number of the command
 */
void _rotatestack(stack_t **ahead, unsigned int line_number)
{
	(void)line_number;
	stack_t *tmp;
	int tmpv = 0, tmpvn = 0, counter = 0;

	tmp = *ahead;
	while (tmp)
	{
		tmpv = tmp->n;
		tmp = tmp->next;
		counter++;
	}
	tmp = *ahead;
	if (counter > 1)
	{
		while (tmp->next)
		{
			tmpvn = tmp->n;
			tmp->n = tmpv;
			tmpv = tmpvn;
			tmp = tmp->next;
		}
		tmp->n = tmpv;
	}
}
/**
 * _pushinqueue - pushes an element to the queue
 * @value: Value to add
 * @ahead: address of the head
 */
void _pushinqueue(stack_t **ahead, unsigned int value)
{

	stack_t *newnode;
	stack_t *lastnode;

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
		error1(4, NULL, value);
	lastnode = *ahead;
	newnode->n = value;
	newnode->next = NULL;
	if (*ahead == NULL)
	{
		head = newnode;
		newnode->prev = NULL;
		return;
	}
	while (lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
	newnode->prev = lastnode;
}
/**
 * readfile - function to read the file
 * @file: pointer to file to read
 */
	void readfile(FILE *file)
	{

	char *line = NULL;
	size_t n = 0;
	int ln = 1;
	int flag = 0;

	while (getline(&line, &n, file) != EOF)
	{
		flag = _split(line, line_number, flag);
		line_number++;
	}
	free(line);
}
/**
 * _split - Separates by lines to determinate the function 
 * @line: String representing a line in a file
 * @ln: line number for the opcode
 * @flag: flag to know if is stack or queue
 * Return: 0 if is stack or 1 if is queue
 */
int _split(char *line, int line_number, int flag)
{
	char *opcode;
	char *value;

	opcode = strtok(line, "\n ");
	value = strtok(NULL, "\n ");

	if (opcode != NULL)
	{
		if (opcode[0] == '#')
			return (flag);
		if (strcmp(opcode, "stack") == 0)
		{
			flag = 0;
			return (flag);
		}
		if (strcmp(opcode, "queue") == 0)
		{
			flag = 1;
			return (flag);
		}
		_opcodefunc(value, opcode, line_number, flag);
	}
	return (flag);
}
/**
  * _opcodefunc - find the specific opcode function
  * @value: value to manipulate
  * @monty: string with monty instruction
  * @ln: the line where is the instruction
  * @flag: flag to know if is stack or queue
  */
void _opcodefunc(char *value, char *monty, int line_number, int flag)
{
	void (*operation)(stack_t **, unsigned int);
	int i = 1, j = 0;
	unsigned int tmpvalue = 0;

	operation = get_op_func(monty);
	if (operation)
	{
		if (strcmp(monty, "push") == 0)
		{
			if (value == NULL)
				error1(5, monty, line_number);
			else if (value[0] == '-')
			{
				value = value + 1;
				i = (i * -1);
			}
			while (value[j])
			{
				if (isdigit(value[j]) == 0)
					error1(5, monty, line_number);
					j++;
			}
			tmpvalue = atoi(value) * i;
			if (flag == 0)
				operation(&head, tmpvalue);
			if (flag == 1)
				_pushinqueue(&head, tmpvalue);
		}
		else
			operation(&head, line_number);
		return;
	}
	error1(3, monty, line_number);
}
