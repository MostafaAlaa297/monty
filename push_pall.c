#include <stdio.h>
#include <stdlib.h>
#include"monty.h"

/**
 * push - A function to add a new element to the stack
 * @stack: The stack
 * @data: The data to make operations on
 * @line_number: The number of the line to track errors
 *
 * Return: Nothing
 */

void push(stack_t **stack, char *arg)
{
	int value = _atoi(arg);
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top of the stack
 * @stack: The stack to make operations on
 *
 * Return: Nothing
 */

void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
