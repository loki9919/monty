#include "monty.h"

/**
 * error_function - function to print in stderr all the errors
 * @error_number: number of the error
 * @file_name: name of the file with bitcode
 * @line_number: line of the monty file that is readed.
 *
 */
void error1(int errorn, char *file_name, int ln)
{
	switch (errorn)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", file_name);
			break;
		case 3:
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, file_name);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			break;
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
			break;
		case 8:
			fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
			break;
		case 9:
			fprintf(stderr, "L%d: can't add, stack too short\n", l_n);
			break;
		case 10:
			fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
			break;
	default:
		return;
	}
	freedlist(head);
	exit(EXIT_FAILURE);
}

/**
 * error1 - function to print in stderr all the errors
 * @errorn: number of the error
 * @ln: line of the monty file that is readed.
 */
void error1(int errorn, int ln)
{
	switch (errorn)
	{
		case 11:
			fprintf(stderr, "L%d: can't div, stack too short\n", ln);
			break;
		case 12:
			fprintf(stderr, "L%d: division by zero\n", ln);
			break;
		case 13:
			fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
			break;
		case 14:
			fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
			break;
		case 15:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
			break;
		case 16:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln;
			break;
	default:
		return;
	}
	freedlist(head);
	exit(EXIT_FAILURE);
}
