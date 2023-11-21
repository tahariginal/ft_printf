NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = ./
TOOLS_HEAD = ./tools/
SRCS = ft_printf.c\
TOOLS_SRC = ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_putadd.c \
			ft_puthex.c
OBJS = $(SRCS:.c=.o)
TOOLS_OBJS = $(TOOLS_SRC:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -I $(HEAD) -I $(TOOLS_HEAD) $(SRCS) $(TOOLS_SRCS)
	$(AR) $(NAME) $(OBJS) $(TOOLS_OBJS)
	
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(TOOLS_OBJS)

re: fclean all

.PHONY: clean fclean all re