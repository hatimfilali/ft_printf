
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ft_needings.c ft_printf.c
OBJ = $(SRC:.c=.o)
$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)
all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $?
clean:
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
