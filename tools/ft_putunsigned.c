#include "tools.h"

int ft_putunsigned(unsigned long nb)
{
    int count;
    char *base;

    base = "0123456789";
    count = 0;
    if (nb >= 10)
        count += ft_putunsigned(nb / 10);
    count += ft_putchar(base[nb % 10]);
    return (count);
}