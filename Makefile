# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 11:25:27 by acouture          #+#    #+#              #
#    Updated: 2023/03/08 15:21:19 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -g -Wextra -Wall -Werror
LIBMLX	:= ./MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:= ./src/main.c \
			./src/map_parsing/map_elements.c \
			./src/map_parsing/map.c \
			./src/map_parsing/map_utils.c \

			
OBJS	:= ${SRCS:.c=.o}
LIBFT_A = 	libft.a
LIBF_DIR = 	inc/libft/
LIBFT  = 	$(addprefix $(LIBF_DIR), $(LIBFT_A))

all: $(NAME)

run : all
	./so_long ./map/map.ber

# libmlx: 
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBF_DIR)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

debug: $(NAME)
	@$(CC) -g $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBF_DIR)
	@rm -f $(OBJS)
	
fclean: clean
	$(MAKE) fclean -C $(LIBF_DIR)
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx