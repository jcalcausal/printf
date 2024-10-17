NAME	=	libftprintf.a

SRCS	=	ft_printf.c	ft_utils.c	ft_utils_2.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
