#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed (excluding the null byte used to end
 * output to strings), or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
int printed_chars = 0;
    unsigned int i = 0;
    char *str;
    va_list args;
    int _putchar(char c);
int _puts(char *str);

va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
                case 'c':
                    printed_chars += _putchar(va_arg(args, int));
                    break;

                case 's':
                    str = va_arg(args, char *);
                    if (str == NULL)
                        str = "(null)";
                    printed_chars += _puts(str);
                    break;
 case '%':
                    printed_chars += _putchar('%');
                    break;

                default:
                    printed_chars += _putchar('%');
                    printed_chars += _putchar(format[i]);
                    break;
            }
        }
        else
        {
            printed_chars += _putchar(format[i]);
        }

        i++;
    }

    va_end(args);

    return (printed_chars);
}
