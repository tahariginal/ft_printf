#include "tools.h"

int    ft_putnbr(int n)
{
        long    nbr;
        int     len;

        nbr = n;
        len = 0;
        if (nbr < 0)
        len = 1;
        while (nbr % 10)
        {
            nbr /= 10;
            len ++;
        }
        nbr = n;
        if (nbr < 0)
        {
                ft_putchar('-');
                nbr *= -1;
        }
        if (nbr >= 0 && nbr <= 9)
                ft_putchar((nbr + 48));
        else
        {
                ft_putnbr((nbr / 10));
                ft_putnbr((nbr % 10));
        }
    return (len);
}