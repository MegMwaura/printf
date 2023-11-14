#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Format
 * @i: parameter.
 * Return: Flags
 */

int get_flags(const char *format, int *i)
{

	int a, current;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	current = *i + 1;
	while (format[current] != '\0')
	{
		a = 0;

		while (FLAGS_CH[a] != '\0')
		{
			if (format[current] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
			a++;
		}

		if (FLAGS_CH[a] == 0)
		{
			break;
		}
		current++;
	}

	*i = current - 1;

	return (flags);
}
