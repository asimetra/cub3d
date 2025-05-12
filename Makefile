NAME = cub3D

MAIN = src/main.c

SRC = libs/memory_allocator/allocator.c \
	libs/memory_allocator/aborter.c \

CC = cc
CFLAGS = -Wall -Wextra -g #-Werror
LIBFT = libs/libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libs/libft

clean:
	rm -f $(OBJ)
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean

re: fclean all

.PHONY: all clean fclean re
