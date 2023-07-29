# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 11:33:37 by jkarosas          #+#    #+#              #
#    Updated: 2022/10/10 13:44:28 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
SRCS = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

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