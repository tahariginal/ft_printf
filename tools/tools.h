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