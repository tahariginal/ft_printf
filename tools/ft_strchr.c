#include "tools.h"
char    *ft_strchr(const char *s, int c)
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