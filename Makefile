S = src/

NAME = so_long.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MINILIBX = -I /usr/X11/include/ -L /usr/X11/lib/ -lmlx -lX11 -lXext -framework OpenGL -framework AppKit

OBJS := $(*.o)

SRC =   $(S)main.c \
        $(S)handle_map.c

all: $(NAME)

${NAME}:
	${CC} ${CFLAGS} ${SRC} ${MINILIBX} -o ${NAME}

clean:
	rm -rf *.o

fclean: clean
	rm -f ${OBJS} $(NAME)

re: fclean ${NAME}

.PHONY: all clean fclean re