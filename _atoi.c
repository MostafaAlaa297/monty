#include "monty.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	/* Check for the sign */
	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	/* Process each character in the string */
	while (s[i] != '\0')
	{
		/* Check for non-digit characters */
		if (s[i] < '0' || s[i] > '9')
		{
			break;
		}

		/* Update the result based on the current digit */
		result = result * 10 + (s[i] - '0');

		i++;
	}

	/* Apply the sign to the result */
	return sign * result;
}
