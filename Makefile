# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouture <acouture@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 15:45:14 by acouture          #+#    #+#              #
#    Updated: 2023/02/07 14:05:13 by acouture         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		so_long

S = 		src/

SRC =		$Smain.c \
			$Shandle_map.c \

OBJS = 		$(SRC:S%=%.o)

CC = 		gcc

CFLAGS = 	-Wall -Werror -Wextra

LINKS = 	-lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJS) $(LINKS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

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