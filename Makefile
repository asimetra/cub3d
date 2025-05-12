NAME	= cub3D

MAIN = srcs/main.c

SRC =

CC = cc
CFLAGS = -Wall -Wextra -g #-Werror
LIBFT = libs/libft/libft.a

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
