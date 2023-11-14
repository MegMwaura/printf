#include "main.h"

/**
 * handle_print - Handles the printing of formatted strings
 * @fmt: Formatted string to be printed.
 * @list: List of arguments.
 * @buffer: Buffer for output.
 * @flags: Flags for formatting.
 * @width: Width for formatting.
 * @precision: Precision for formatting.
 * @size: Size for formatting.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int handle_print(const char *fmt, va_list list, char *buffer, 
			int flags, int width, int precision, int size)
{
	int i = 0;
	int count_chars = 0;
	int unknow_len = 0;

	struct
	{
	char fmt;
	int (*fn)(va_list, char *, int, int, int, int);
	} fmt_types[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
	{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
	{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	while (fmt[i] != '\0')
	{
	if (fmt[i] == fmt_types[i].fmt)
	{
		return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}
	i++;
	}
	
	if (fmt_types[i].fmt == '\0')
	{
	if (fmt[i] == '\0')
		return (-1);
	unknow_len += write(1, "%%", 1);
	if (fmt[i - 1] == ' ')
		unknow_len += write(1, " ", 1);
	else if (width)
	{
		--i;
		while (fmt[i] != ' ' && fmt[i] != '%')
		--i;
	if (fmt[i] == ' ')
		--i;
	return (1);
	}
	unknow_len += write(1, &fmt[i], 1);
	return (unknow_len);
	}
	return (count_chars);
}
