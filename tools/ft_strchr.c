/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:32:50 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 12:18:05 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (t_byte)c)
			return ((char *)s);
		s++;
	}
	if (*s == (t_byte)c)
		return ((char *)s);
	return (NULL);
}
