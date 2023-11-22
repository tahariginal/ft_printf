/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkoulal <tkoulal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:31:50 by tkoulal           #+#    #+#             */
/*   Updated: 2023/11/22 09:31:53 by tkoulal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT
# define LIBFT

# include <unistd.h>
# include <stdarg.h>

typedef unsigned char t_byte;

int     ft_putchar(char c);
int     ft_putstr(const char *str);
int     ft_putnbr(int n);
size_t     ft_strlen(const char *s);
int ft_puthex(unsigned long, char p);
int ft_putadd(size_t n,char specif);
char    *ft_strchr(const char *s, int c);
int ft_putunsigned(unsigned long nb);

#endif
