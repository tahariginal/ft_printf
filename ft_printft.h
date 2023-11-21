#ifndef PRINTF_FT
# define PRINTF_FT

# include "./tools/tools.h"

int ft_printf(const char *format, ...);
int ft_print_type(char specifier, va_list ap);

#endif