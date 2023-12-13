#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

#define MAX_STR 10

/**
 * main - Entry Point for monty lang
 *
 * Return: 0 on success, and 1 otherwise
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file ==NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;

	char opcode[100];
	int argument;

	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (_strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%d", &argument) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, argument);
		}
		else if (_strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}

		line_number++;
	}

	fclose(file);

	return (EXIT_SUCCESS);
}
