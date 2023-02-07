# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 15:45:14 by acouture          #+#    #+#              #
#    Updated: 2023/02/07 14:36:50 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

S = 		src/

SRC =		$Smain.c

LIBFT_A = 	libft.a
LIBF_DIR = 	inc/libft/
LIBFT  = 	$(addprefix $(LIBF_DIR), $(LIBFT_A))

OBJS = 		*.o

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra

LINKS = 	-lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(LIBFT) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJS): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FALGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all