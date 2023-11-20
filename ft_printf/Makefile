NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror
SRC = ft_printf.c \
	  printf_int.c \
	  printf_str.c
OBJS= $(patsubst %.c, %.o, $(SRC))
AR = ar -cr

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
