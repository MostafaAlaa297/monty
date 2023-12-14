#include <stdio.h>
#include "monty.h"
/**
 * pint - Prints the value at the top of the stack,
 * followed by a new line
 * @stack: The stack to operate on
 *
 * Return: Nothing
 */

void pint(stack_t **stack)
{
	stack_t *current = *stack;

	printf("%d\n", current->n);
	current = current->next;
}
