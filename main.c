#include "monty.h"
stack_t *head = NULL;

/**
 * main - function main
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: always 0
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
		error1(1, av[1], ac);
	if (access(av[1], R_OK) == -1)
		error1(2, av[1], ac);
	file = fopen(av[1], "r");
	if (file == NULL)
		error_function(2, av[1], ac);
	readfile(file);
	fclose(file);
	freedlist(head);
	return (0);
}
