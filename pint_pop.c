#include "monty.h"
/**
 * pint - to print top element.
 * @head: head
 * @ln: line number
 */
void pint(stack_t **head, unsigned int ln)
{

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*head)->n);
}
/**
 * pop_fun - function that remove element.
 * @h: head
 * @linen: line number
 */
void pop_fun(stack_t **h, unsigned int linen)
{
	stack_t *current;

	current = *h;
	if (current == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", linen);
		exit(EXIT_FAILURE);
	}
	*h = current->next;
	if (*h != NULL)
		(*h)->prev = NULL;
	free(current);
}
