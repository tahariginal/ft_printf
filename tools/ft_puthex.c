/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:32:22 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 12:17:50 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_puthex(unsigned long nb, char p)
{
	int		count;
	char	*base;

	count = 0;
	if (p == 'x')
		base = "0123456789abcdef";
	if (p == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		count += ft_puthex(nb / 16, p);
	count += ft_putchar(base[nb % 16]);
	return (count);
}
