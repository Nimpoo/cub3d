CC = gcc
CFLAGS = -Werror -Wextra -Wall

SRC = $(addprefix src/, main.c get_next_line.c key_handler.c ft_rotate_vector.c ft_move.c ft_loop.c ft_dda.c ft_draw.c ft_exit.c ft_minimap.c $(addprefix parsing/, file.c texture.c map.c utils.c))
OBJ = $(SRC:.c=.o)

LIB_SRC = $(addprefix src/lib/, ft_strlen.c ft_calloc.c ft_put.c ft_strdup.c ft_strcmp.c ft_split.c ft_atoi.c ft_isspace.c ft_convert_rgba.c)
LIB_OBJ = $(LIB_SRC:.c=.o)
LIB = src/lib/lib.a

NAME = cub3D

$(NAME): minilibx/libmlx.a $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -Lminilibx -framework Opengl -framework Appkit minilibx/libmlx.a $(OBJ) $(LIB) -o $(NAME)

$(LIB): $(LIB_OBJ)
	ar rcs $(LIB) $(LIB_OBJ)

init: dependencies minilibx/libmlx.a

dependencies:
	curl https://raw.githubusercontent.com/Nimpoo/cub3d/dev/dependencies.tgz -o dependencies.tgz
	tar -xf dependencies.tgz
	rm dependencies.tgz

minilibx/libmlx.a:
	curl https://raw.githubusercontent.com/Nimpoo/cub3d/dev/minilibx.tgz -o minilibx.tgz
	tar -xf minilibx.tgz
	rm minilibx.tgz
	make -C minilibx

all: $(NAME)

run: all
	./$(NAME) maps/subject.cub

clean:
	rm -f $(LIB_OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

fclean_init:
	rm -rf maps
	rm -rf minilibx
	rm -rf textures

re: fclean all

.PHONY: all clean fclean re dependencies init
