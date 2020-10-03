# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmira <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 17:48:55 by fmira             #+#    #+#              #
#    Updated: 2020/09/21 19:05:55 by fmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  ft_display_file
SRC = ft_display_file.c arg_errors.c ft_putstr.c ft_puterr.c
OBJ = ft_display_file.o arg_errors.o ft_putstr.o ft_puterr.o
FLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc -c $(FLAGS) $(SRC) && gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
