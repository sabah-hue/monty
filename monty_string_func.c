#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Result: Nothing
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_element;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ascii_element = (*stack)->n;
	if (ascii_element < 0 || ascii_element > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ascii_element);
}
