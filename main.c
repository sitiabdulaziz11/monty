#define _POSIX_C_SOURCE 200809L
#include "monty.h"
void fun(void);
instruction_t opcd[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop_fun},
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
	stack_t *stack;
	char *line = NULL, *ptr;
	unsigned int linen = 1;
	size_t linel = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
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
				fprintf(stderr, "L%u: unknown instruction %s\n", linen, ptr);
				free(line);
				fclose(fd);
				exit(EXIT_FAILURE);
			}
		}
		linen++;
	}
	free_instrcn(stack);
	fclose(fd);
	return (EXIT_SUCCESS);
}
