# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 14:08:40 by acouture          #+#    #+#              #
#    Updated: 2023/04/01 08:23:12 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./
OBJ_PATH = obj/

SRC :=	ft_atoi.c \
	 	ft_bzero.c \
		ft_calloc.c \
	 	ft_isalnum.c \
	 	ft_isalpha.c \
	 	ft_isascii.c \
	 	ft_isdigit.c \
	 	ft_isprint.c \
	 	ft_itoa.c \
	 	ft_memchr.c \
	 	ft_memcmp.c \
	 	ft_memcpy.c \
	 	ft_memmove.c \
	 	ft_memset.c \
	 	ft_putchar_fd.c \
	 	ft_putendl_fd.c \
	 	ft_putnbr_fd.c \
	 	ft_putstr_fd.c \
	 	ft_split.c \
	 	ft_strchr.c \
	 	ft_strdup.c \
	 	ft_striteri.c \
	 	ft_strjoin.c \
	 	ft_strlcat.c \
	 	ft_strlcpy.c \
	 	ft_strlen.c \
	 	ft_strmapi.c \
	 	ft_strncmp.c \
	 	ft_strnstr.c \
	 	ft_strrchr.c \
	 	ft_strtrim.c \
	 	ft_substr.c \
	 	ft_tolower.c \
	 	ft_toupper.c \
		ft_error.c \
		ft_realloc.c \
		ft_swap.c \
		\
		ft_printf_n/ft_itoa_to_hexa.c \
		ft_printf_n/ft_printf.c \
		ft_printf_n/ft_putchar_printf.c \
		ft_printf_n/ft_putnbr_printf.c \
		ft_printf_n/ft_putnbr_unsigned_printf.c \
		ft_printf_n/ft_putpointer_fd.c \
		ft_printf_n/ft_putstr_printf.c \
		ft_printf_n/ft_strlen_printf.c \
		\
		get_next/get_next_line_utils.c \
		get_next/get_next_line.c \
		\
		lst/ft_lstnew.c \
		lst/ft_lstadd_front.c \
		lst/ft_lstsize.c \
		lst/ft_lstlast.c \
		lst/ft_lstadd_back.c \
		lst/ft_lstdelone.c \
		lst/ft_lstclear.c \
		lst/ft_lstiter.c \
		lst/ft_lstmap.c \
		
GREEN = \033[0;92m

SRCS 	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
	@exec 2>/dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "$(GREEN)Libft compiling: done\n"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re