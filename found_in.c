int found_in(char *arr, char target)
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
    return found;
}
