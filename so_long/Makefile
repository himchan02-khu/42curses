NAME = so_long

CC = cc
CFLAG = -Wall -Wextra -Werror -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit
SRC = main.c
OBJS= $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME) $(MLX_FLAGS)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
