/**
 * _found_in - writes the character c to stdout
 * @arr: array to search in
 * @target: char to search for
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _found_in(char *arr, char target)
{
	int found = 0;

	while (*arr != '\0')
	{
		if (*arr == target)
		{
			found = 1;
		}
		arr++;
	}
	return (found);
}
