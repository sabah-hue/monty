#include "monty.h"

/**
 * main - entry point
 *
 * Description: A function that start the monty project
 * @ac: number of input arguments
 * @av: argument vector
 *
 * Return: 0 in success
 */
int main(int ac, char **av)
{
	FILE *file_ptr;

	if (ac < 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(av[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", av[1]);
		exit(EXIT_FAILURE);
	}
	_getline(file_ptr);
	fclose(file_ptr);
	exit(EXIT_SUCCESS);
}
