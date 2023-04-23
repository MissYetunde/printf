#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _puts - writes the string s to stdout
 * @s: The string to print
 *
 * Return: On success, the number of characters printed.
 * On error, a negative value is returned.
 */
int _puts(char *s)
{
    int i = 0;

    while (s[i])
    {
        _putchar(s[i]);
        i++;
	   }

    return (i);
}
