# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 21:44:31 by jkarosas          #+#    #+#              #
#    Updated: 2022/09/10 15:18:41 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRCS = main.cpp phonebook.cpp contact.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = ${SRCS:.cpp=.o}

all:	$(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re