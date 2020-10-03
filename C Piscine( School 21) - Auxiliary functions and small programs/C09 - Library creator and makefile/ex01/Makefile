PATH_SRC = ./srcs/
HEAD = ./includes/
NAME = libft.a
U_HEAD = -I $(HEAD)
FLAGS = -Wall -Werror -Wextra
SRC = $(PATH_SRC)ft_putchar.c $(PATH_SRC)ft_putstr.c $(PATH_SRC)ft_swap.c $(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_strcmp.c
OBJ = ft_putchar.o ft_putstr.o ft_swap.o ft_strlen.o ft_strcmp.o

$(NAME):
		gcc -c $(U_HEAD) $(FLAGS) $(SRC) && ar rc $(NAME) $(OBJ) && mv $(OBJ) $(PATH_SRC)

all: $(NAME)

clean:
	rm -f $(PATH_SRC)ft_putchar.o $(PATH_SRC)ft_putstr.o $(PATH_SRC)ft_swap.o $(PATH_SRC)ft_strlen.o $(PATH_SRC)ft_strcmp.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
