NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = ./
TOOLS_HEAD = ./tools/
SRCS = ft_printf.c\
		ft_print_type.c

TOOLS_SRC = ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strchr.c \
			ft_strlen.c \
			ft_putadd.c \
			ft_puthex.c\
			ft_putunsigned.c
PRETOOLS = $(addprefix $(TOOLS_HEAD), $(TOOLS_SRC))
OBJS = $(SRCS:.c=.o)
TOOLS_OBJS = $(TOOLS_SRC:.c=.o)
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) $(PRETOOLS)
	$(AR) $(NAME) $(OBJS) $(TOOLS_OBJS)
	
fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS) $(TOOLS_OBJS)

re: fclean all

.PHONY: clean fclean all re