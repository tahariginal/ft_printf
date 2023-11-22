/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:32:43 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 12:18:02 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_putunsigned(unsigned long nb)
{
	int		count;
	char	*base;

	base = "0123456789";
	count = 0;
	if (nb >= 10)
		count += ft_putunsigned(nb / 10);
	count += ft_putchar(base[nb % 10]);
	return (count);
}
