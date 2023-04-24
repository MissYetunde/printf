#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * my_printf - prints formatted output to stdout
 *
 * @format: format string containing conversion specifiers
 *
 * Return: number of characters printed
 */
void my_printf(const char *format, ...)
{
	va_list arg;
	int value;
	char *p;

	va_start(arg, format);

	for (p = (char *)format; *p != '\0'; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}

		switch (*(++p))
		{
		case 'd':
		case 'i':
			value = va_arg(arg, int);
			printf("%d", value);
			break;
		default:
			putchar('%');
			putchar(*p);
			break;
		}
	}

	va_end(arg);
}
