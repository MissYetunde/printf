#include <main.h>

/****************** Prints a char *************/

/**
 * print_char - prints a char data type.
 * @typ: List of arguments
 * @buffer: the buffer array to handle print
 * @flags: it calculates the active flags
 * @width: checks width
 * @precisn: precision specification
 * @size: tells size
 * Return: Numbers of char printed
 */
int print_char(va_list typ, char buffer[],
	int flags, int width, int precisn, int size)
{
	char c = va_arg(typ, int);

	return (handle_write_char(c, buffer, flags, width, precisn, size));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @typ: List n of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width.
 * @precisn: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list typ, char buffer[],
	int flags, int width, int precisn, int size)
{
	int length = 0, i;
	char *str = va_arg(typ, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precisn);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precisn >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precisn >= 0 && precisn < length)
		length = precisn;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - It prints a percent sign
 * @typ: List n of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precisn: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precisn, int size)
{
	UNUSED(typ);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precisn);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - it prints int
 * @typ: List n of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precisn: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list typ, char buffer[],
	int flags, int width, int precisn, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - it prints an unsigned number
 * @typ: List n of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precisn: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list typ, char buffer[],
	int flags, int width, int precisn, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precisn);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
