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
 * _sub - subtracts the top element of the stack from the second top element of the stack.
 * @stack: pointer to head node
 * @line/-number: input argument
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
