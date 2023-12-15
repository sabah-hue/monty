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
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	sum = sum + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int sub_element;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sub_element = (*stack)->n;
	sub_element = (*stack)->next->n - sub_element;
	_pop(stack, line_number);
	(*stack)->n = sub_element;
}

/**
 * _div - divides the second top element
 * of the stack by the top element of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int element;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	element = (*stack)->n;
	if (element == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n / element;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _mul - multiplies the second top e with the top e of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int element;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	element = (*stack)->n;
	result = (*stack)->next->n * element;
	_pop(stack, line_number);
	(*stack)->n = result;
}

/**
 * _mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: pointer to head node
 * @line_number: input argument
 *
 * Return: Nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int element;
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	element = (*stack)->n;
	if (element == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % element;
	_pop(stack, line_number);
	(*stack)->n = result;
}
