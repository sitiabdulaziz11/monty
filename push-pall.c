#include "monty.h"

/**
 * push - push elements to the stack.
 * @stack: doubly linked list
 * @line_number: number of line.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argmnt;
	stack_t *newn;
	int val;

	argmnt = strtok(NULL, " \t\n");

	if (!argmnt)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	val = atoi(argmnt);

	newn = malloc(sizeof(stack_t));
	if (newn == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newn->n = val;
	newn->prev = NULL;
	newn->next = *stack;
	if (*stack)
		(*stack)->prev = newn;
	*stack = newn;
}

/**
 * pall - print or display elements in the stack.
 * @stack: doubly linked list.
 * @linen: line number.
 */
void pall(stack_t **stack, unsigned int linen)
{
	stack_t *currt;

	(void)linen;
	currt = *stack;
	while (currt)
	{
		fprintf(stdout, "%d\n", currt->n);
		currt = currt->next;
	}
}
/**
 * free_instrcn - function for freeing.
 * @h: head
 */
void free_instrcn(stack_t *h)
{
	stack_t *ptr;

	while (h)
	{
		ptr = h;
		h = h->next;
		free(ptr);
	}
}

