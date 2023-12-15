#include "monty.h"

/**
 * _pall - Print elements in stack.
 *
 * Description: Function to print all values in stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void) line_number;
	node = *stack;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * _pint - prints the value at the top of the stack.
 *
 * Description: Function that print value at top of stack
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * _pop - removes the top element of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return; Nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	node = (*stack)->next;
	free(*stack);
	*stack = node;
}

/**
 * _swap - swaps the top two elements of the stack.
 *
 * Description: Function that swaps the top two elements of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = i;
}

/**
 * _nop - doesn’t do anything.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
