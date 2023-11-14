#include "main.h"

int _printf(const char *format, ...) {
    va_list list;
    char buffer[BUFF_SIZE];
    int i = 0;  /* Assuming i is the position in the format string */
    int count = 0;

    va_start(list, format);

    while (format && format[i] != '\0') {
        if (format[i] != '%') {
            buffer[count++] = format[i];
            if (count == BUFF_SIZE) {
                /* Handle buffer overflow */
            }
        } else {
            int flags = get_flags(format, &i);
            int width = get_width(format, &i, list);
            int precision = get_precision(format, &i, list);
            int size = get_size(format, &i);

            count += handle_print(format, list, buffer, flags, width, precision, size);
        }

        i++;
    }

    /* Ensure null-termination of the buffer */
    buffer[count] = '\0';

    /* Print or use the formatted output as needed */

    va_end(list);
    return count;
}
