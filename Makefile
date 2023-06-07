# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/06 11:25:27 by acouture          #+#    #+#              #
#    Updated: 2023/04/02 10:49:10 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast 
LIBMLX	:= ./MLX42

OBJ_PATH = obj/
SRC_PATH = src/
HEADERS	:= -I ./include -I $(LIBMLX)/include 
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
SRC	:= main.c \
			map_parsing/map_elements.c \
			map_parsing/map.c \
			map_parsing/map_utils.c \
			graphic/graphic_main.c \
			graphic/graphic_utils.c \
			graphic/graphic_move.c \
			graphic/graphic_loops.c \
			graphic/graphic_img.c \
			graphic/graphic_textures.c \


SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:%.c=%.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
LIBFT_A = 	libft.a
LIBF_DIR = 	inc/libft/
LIBFT  = 	$(addprefix $(LIBF_DIR), $(LIBFT_A))

GREEN = \033[0;92m
RED = \033[0;91m
RESET = \033[0m

all: libmlx makelibft $(NAME)
	@exec 2>/dev/null

run : all
	@./$(NAME) ./map/map1.ber

libmlx: 
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

makelibft:
	@$(MAKE) -C $(LIBF_DIR)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)So_long compiling: done$(RESET)\n"

debug: $(NAME)
	@$(CC) -g $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBF_DIR)
	@rm -rf $(LIBMLX)/build
	@rm -f $(OBJS)
	@printf "$(RED)Clean: done$(RESET)\n"

	
fclean: clean
	@$(MAKE) fclean -C $(LIBF_DIR)
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx