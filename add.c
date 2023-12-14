#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * stack: A pointer to a pointer
 * to the top elemant of the top element of the stack
 * @line_number: The number of the line with error
 *
 * Return: Noting
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *top = *stack;
	stack_t *second = top->next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top->next = second->next;
	if (top->next != NULL)
	{
		top->next->prev = top;
	}
	sum = top->n + second->n;
	second->n = sum;

	*stack = second;
	free(top);
}
