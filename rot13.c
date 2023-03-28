#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * rot13 - Encodes a string using rot13.
 * @str: The string to be encoded.
 *
 * Return: A pointer to the encoded string.
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
            // Only increment alphabet characters
            if ((*current_char >= 97 && *current_char <= 122) || (*current_char >= 65 && *current_char <= 90))
            {
                if (*current_char > 109 || (*current_char > 77 && *current_char < 91))
                {
                    // Characters that wrap around to the start of the alphabet
                    *current_char -= 13;
                }
                else
                {
                    // Characters that can be safely incremented
                    *current_char += 13;
                }
            }
            current_char++;
        }
    }
    *sum += _putstring(result);
}
