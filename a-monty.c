#include "monty.h"

/**
 * main - Entry point.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: 0
 */
stack_t *stack = NULL;

int main(int ac, char *av[])
{
	FILE *fd;
	char line[MAX_LEN], *ptr;
	unsigned int linen = 1;

	if (ac != 2)
	{
		printf("USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), fd) != NULL)
	{
		ptr = strtok(line, " \t\n");
		if (ptr)
		{
			if (strcmp(ptr, "push") == 0)
			{
				push(&stack, linen);
			}
			if (strcmp(ptr, "pall") == 0)
			{
				pall(&stack);
			}
		}
	}
	return (0);
}
