#include "monty.h"
#include <stdio.h>

/**
 * read_line - read from open file
 *
 * Description: Function that read from file
 * @file_ptr: pointer to open file
 *
 * Return: nothing
 */
void read_line(FILE *file_ptr)
{
	char *user_data = NULL;
	size_t buffer_size = 0;
	ssize_t chars_num = 0;
	unsigned int which_line = 0;
	char *splits = NULL;
	stack_t *stack = NULL;

	while (1)
	{
		chars_num = getline(&user_data, &buffer_size, file_ptr);
		if (chars_num == -1)
			break;
		which_line++;
		splits = strtok(user_data, " \n\t");
		if (splits)
			which_opcode(splits, which_line, &stack);
	}
	free(user_data);
	_free_stack(&stack);
}

/**
 * which_opcode - identify the matching function
 *
 * Description: Function that return function which matching with input command
 * @splits: input command
 * @which_line: line number
 * @stack: input argument
 *
 * Return: nothong
 */
void which_opcode(char *splits, unsigned int which_line, stack_t **stack)
{
	unsigned int i = 0;
	instruction_t handle_opcode[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"nop", _nop},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	while (handle_opcode[i].opcode != NULL)
	{
		if (!strcmp(splits,  handle_opcode[i].opcode))
		{
			handle_opcode[i].f(stack, which_line);
			return;
		}
		i++;
	}
	if (splits[0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", which_line, splits);
		exit(EXIT_FAILURE);
	}
	if (splits[0] == '#')
	{
		handle_opcode[7].f(stack, which_line);
		return;
	}
}
