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
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
        char opcode[100];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file ==NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fscanf(file, "%s", opcode) != EOF)
	{
		if (_strcmp(opcode, "push") == 0)
		{
			char arg[100];
			if (fscanf(file, "%s", arg) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			push(&stack, arg);
		}
		else if (_strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (_strcmp(opcode, "pint") == 0)
                {
                        pint(&stack);
                }
		else if (_strcmp(opcode, "pop") == 0)
                {
                        pop(&stack);
                }
		else if (_strcmp(opcode, "swap") == 0)
                {
                        swap(&stack, line_number);
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
