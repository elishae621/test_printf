#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_rot13 - Encodes a string using rot13.
 * @str: The string to be encoded.
 * @sum: Sum of bytes written
 */
void print_rot13(char *str, int *sum)
{
	char *current_char, *result;

	result = malloc(strlen(str));
	current_char = malloc(strlen(str));

	if (result != NULL)
	{
		strcpy(result, str);

		current_char = result;

		while (*current_char != '\0')
		{
			if ((*current_char >= 97 && *current_char <= 122) ||
				(*current_char >= 65 && *current_char <= 90))
			{
				if (*current_char > 109 || (*current_char > 77 && *current_char < 91))
				{
					*current_char -= 13;
				}
				else
				{
					*current_char += 13;
				}
			}
			current_char++;
		}
	}
	*sum += _putstring(result);
}
