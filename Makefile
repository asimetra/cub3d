NAME = cub3D

SRC = libs/memory_allocator/allocator.c \
	libs/memory_allocator/aborter.c \
	libs/get_next_line/get_next_line.c \
	src/utils/string_utils/str_arr_operations.c \
	src/utils/string_utils/str_operations.c \
	src/utils/error_handler.c \
	src/utils/convertion_utils.c \
<<<<<<< HEAD
=======
	src/utils/time_utils.c \
	src/utils/init_utils.c \
>>>>>>> 0acf8bb
	src/element/element_list.c \
	src/element/operations.c \
	src/element/element_type.c \
	src/parser/states.c \
	src/parser/classify.c \
	src/parser/parser.c \
	src/validation/validate_elements.c \
	src/validation/validate_map.c \
	src/validation/validate_utils.c \
	src/graphics/init_graphics.c \
<<<<<<< HEAD
=======
	src/graphics/render.c \
	src/graphics/draw.c \
	src/graphics/dda.c \
	src/event/key_events.c \
	src/event/init_events.c \
	test/draw.c \
>>>>>>> 0acf8bb
	src/main.c \

CC = cc
CFLAGS = -Wall -Wextra -g -Werror  -I./libs -I./includes -I./libs/libft #-fsanitize=address
MINILBX = libs/minilibx/libmlx.a
MINILBX_P = libs/minilibx
MLXFLAG = -lXext -lX11 -lm

LIBFT = libs/libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILBX)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MINILBX) $(MLXFLAG)

$(LIBFT):
	make -C libs/libft

$(MINILBX):
	make -C $(MINILBX_P)

clean:
	rm -f $(OBJ)
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean

re: fclean all

.PHONY: all clean fclean re
