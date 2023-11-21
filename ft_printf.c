#include "ft_printft.h"

int ft_printf(const char *format, ...)
{
    int count;
    va_list arg_p;

    if (!format)
        return (-1);
    count = 0;
    va_start(arg_p,format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (ft_strchr("cspdiuxX%", *format))
            {
                count += ft_print_type(*format, arg_p);
            }
        }
        else
            count += ft_putchar(*format);
    format++;
    }
    va_end(arg_p);
    return (count);
}