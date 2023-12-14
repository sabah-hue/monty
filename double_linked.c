#include "monty.h"

/**
 * _free_stack - frees a stack.
 *
 * Description: A function frees a stack.
 * @head: pointer to head node
 *
 * Return: nothing
 */
void _free_stack(stack_t *head)
{
	stack_t *node;
	
	if (head == NULL)
		return;
	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}


