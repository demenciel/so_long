NAME = libftprintf.a

SRC =	ft_printf.c \
		ft_putnbr_unsigned_fd.c \
		ft_putpointer_fd.c \
		ft_itoa_to_hexa.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c \
		
OBJS = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME) $(SRC)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
