#include "tools.h"

int ft_putadd(size_t n,char specif)
{
    int count;

    if (n == 0)
        return (ft_putstr("(nil)"));
    count = 0;
    count += ft_putstr("0x");
    count += ft_puthex(n, specif);
return (count);
}