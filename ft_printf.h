/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:31:16 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 11:01:12 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT
# define PRINTF_FT

# include "./tools/tools.h"

int	ft_printf(const char *format, ...);
int	ft_print_type(char specifier, va_list ap);

#endif
