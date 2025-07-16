NAME = cub3D

SRC = libs/memory_allocator/allocator.c \
	libs/memory_allocator/aborter.c \
	src/main.c \

CC = cc
CFLAGS = -Wall -Wextra -g -Werror

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
