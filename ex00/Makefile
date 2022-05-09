# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 22:25:13 by dzivanov          #+#    #+#              #
#    Updated: 2022/04/22 23:13:03 by dzivanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= convertor

SRC= main.cpp Convertor.cpp

CC=c++

CFLAGS= -Wall -Werror -Wextra -std=c++98 -o

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS) $(NAME)

clean:
	@rm -f ./*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re