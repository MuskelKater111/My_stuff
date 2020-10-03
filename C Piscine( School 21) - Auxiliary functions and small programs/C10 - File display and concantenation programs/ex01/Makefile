# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmira <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 17:48:55 by fmira             #+#    #+#              #
#    Updated: 2020/09/22 17:44:14 by fmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ft_cat
SRC = ft_putstr.c ft_puterror.c ft_cat.c ft_strcmp.c show_stdin.c show_err.c show_files.c
OBJ = ft_putstr.o ft_puterror.o ft_cat.o ft_strcmp.o show_stdin.o show_err.o show_files.o
FLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc -c $(FLAGS) $(SRC) && gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
