#include "monty.h"

/**
  * get_op_func - find the opcode function to use
  * @s: monty instruction
  * Return: always NULL
  */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t _functions[] = {
		{"push", _push_stack},
		{"pall", printall},
		{"pint", printtop},
		{"pop", removetop},
		{"swap", swaptwotop},
		{"add", addtwotop},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _printchar},
		{"pstr", _printstring},
		{"rotl", _rotate},
		{"rotr", _rotatestack},
		{NULL, NULL}
	};
	int i = 0;

	while (_functions[i].opcode)
	{
		if (!(strcmp(_functions[i].opcode, s)))
			return (_functions[i].f);
		i++;
	}
	return (NULL);
}
