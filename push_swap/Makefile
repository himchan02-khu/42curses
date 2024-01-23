NAME = push_swap

CC = cc
CFLAG = -Wall -Wextra -Werror
SRC = ft_printf.c \
	  printf_int.c \
	  printf_str.c \
	  main.c
OBJS= $(patsubst %.c, %.o, $(SRC))
#AR = ar -cr

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
