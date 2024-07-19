NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main.c ft_str.c read.c write.c validator.c solver.c util.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c bsq.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re all
