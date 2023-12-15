#include "monty.h"

/**
 * _free_stack - frees a stack.
 *
 * Description: A function frees a stack.
 * @head: pointer to head node
 *
 * Return: nothing
 */
void _free_stack(stack_t **head)
{
	stack_t *node;

	if (*head == NULL)
		return;
	while (*head)
	{
		node = *head;
		*head = (*head)->next;
		free(node);
	}
}

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 *
 * Description: A function that adds node at the beginning of a list.
 * @head: pointer to head node
 * @n: integer
 *
 * Return: address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new_head;

	if (head == NULL)
		return (NULL);
	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
		return (NULL);
	new_head->n = n;
	new_head->prev = NULL;
	new_head->next = *head;
	if (*head)
		(*head)->prev = new_head;
	else
	{
		new_head->next = NULL;
	}
	*head = new_head;

	return (new_head);
}

/**
 * _push - add new element to stack
 *
 * Description: Function that added new element at stack
 * @stack: pointervto pointer to head.
 * @line_number: input argument
 *
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *token = NULL;
	int i;

	token = strtok(NULL, " \n\t");
	if (!token)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] != '-' && !isdigit(token[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	add_dnodeint(stack, atoi(token));
}

