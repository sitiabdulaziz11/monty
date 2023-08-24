#define _POSIX_C_SOURCE 200809L
#include "monty.h"

void fun(void);
stack_t *stack = NULL;
instruction_t opcd[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

/**
 * main - Entry point.
 * @ac: argument count.
 * @av: argument vector.
 *
 * Return: 0
*/
int main(int ac, char *av[])
{
	int i, fond;
	FILE *fd;
	char *line = NULL, *ptr;
	unsigned int linen = 1;
	size_t linel = 0;

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

	while (getline(&line, &linel, fd) != -1)
	{
		ptr = strtok(line, " \t\n");
		if (ptr)
		{
			fond = 0;
			for (i = 0; opcd[i].opcode != NULL; i++)
			{
				if (strcmp(opcd[i].opcode, ptr) == 0)
				{
					fond = 1;
					opcd[i].f(&stack, linen);
					break;
				}
			}
			if (!fond)
			{
				printf("L%u: unknown instruction %s\n", linen, ptr);
				free(line);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
		linen++;
	}
	fclose(fd);
	return (EXIT_SUCCESS);
}