/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:31:07 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 09:31:09 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printft.h"

int ft_print_type(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'd' || specifier == 'i')
        count += ft_putnbr(va_arg(ap, int));
    else if (specifier == 'c')
        count += ft_putchar(va_arg(ap, int));
    else if (specifier == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if (specifier == 'u')
        count += ft_putunsigned(va_arg(ap, unsigned int));
    else if (specifier == 'x' || specifier == 'X')
        count += ft_puthex(va_arg(ap, unsigned int), specifier);
    else if (specifier == 'p')
        count += ft_putadd(va_arg(ap, unsigned long),'x');
    else
        count += ft_putchar(specifier);
   return (count);
}
