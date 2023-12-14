#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pop - Removes the top element of the stack
 * @stack: The top of the stack
 *
 * Return: Nothing
 */

void pop(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
