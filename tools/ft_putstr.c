/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:32:35 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 09:32:39 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int ft_putstr(const char *str)
{
    if (!str)
        return (ft_putstr("(null)"));
    return (write(1, str, ft_strlen(str)));
}
