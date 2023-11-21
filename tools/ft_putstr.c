#include "tools.h"
int ft_putstr(const char *str)
{
    if (!str)
        return (ft_putstr("(null)"));
    return (write(1, str, ft_strlen(str)));
}