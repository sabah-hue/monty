#include "monty.h"

/**
 * _getline - read from open file
 *
 * Description: Function that read from file
 * @file_ptr: pointer to open file
 *
 * Return: nothing
 */
void _getline(FILE *file_ptr)
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
		splits = strtok(user_data, " \n\t");
		which_line++;
		if (splits)
			which_opcode(splits, which_line, stack);
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
void which_opcode(char *splits, unsigned int which_line, stack_t *stack)
{
	int i = 0;
	instruction_t handle_opcode[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (handle_opcode[i].opcode != NULL)
	{
		if (!strcmp(token,  handle_opcode[i].opcode))
		{
			 handle_opcode[i].f(stack, which_line);
			 return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", which_line, token);
	_free_stack(stack);
	exit(EXIT_FAILURE);
}
