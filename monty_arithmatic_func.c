#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 *
 * Description: Function that adds the top two elements of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
