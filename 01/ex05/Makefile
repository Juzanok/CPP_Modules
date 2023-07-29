# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:43:04 by jkarosas          #+#    #+#              #
#    Updated: 2022/09/20 17:43:18 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl
SRCS = main.cpp Harl.cpp

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