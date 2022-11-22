NAME = so_long
LIBFTNAME = libft.a
MLXNAME = libmlx.a

CFLAGS =-Wall -Werror -Wextra
MLXFLAGS = -framework AppKit -framework OpenGL -L ./minilibx -lmlx -Imlx 
DEBUG = -g -O0

OBJS = $(*.o)

SRCS = srcs/so_long.c \
		srcs/check_read_map.c \
		srcs/check_map.c \
		srcs/check_map_algo.c \
		srcs/window_manager.c \
		srcs/window_texture_init.c \
		srcs/player_movement_1.c \
		srcs/player_movement_2.c \
		srcs/player_exit.c \
		srcs/check_symbol.c \
		srcs/bonnus.c 
LIBFTPATH = ./libft/
MLXPATH = ./minilibx/

all: $(NAME)

${NAME}:
	make -C ${LIBFTPATH}
	make -C ${MLXPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	mv $(MLXPATH)${MLXNAME} ${MLXNAME}
	${CC} ${CFLAGS} ${MLXFLAGS} ${SRCS} ${LIBFTNAME} ${MLXNAME} -o ${NAME}

clean:
	rm -rf *.o

fclean:clean
	rm -rf $(MLXNAME) $(LIBFTNAME) $(OBJ) $(NAME) 

fclean_all:clean
	rm -rf $(MLXNAME) $(LIBFTNAME) $(OBJ) $(NAME)

re: fclean all
