#include <string.h>
#include <unistd.h>

/**
 * _putstring - writes the string s to stdout
 * @s: The string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putstring(char *s)
{
	char buffer[1024];
	int buffer_length;

	strcpy(buffer, s);
	buffer_length = strlen(buffer);
	return (write(1, s, buffer_length));
}
