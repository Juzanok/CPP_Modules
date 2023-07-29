# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/11 06:49:35 by jkarosas          #+#    #+#              #
#    Updated: 2022/10/25 14:27:14 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SRCS = main.cpp Fixed.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = ${SRCS:.cpp=.o}

all:	$(NAME)

$(NAME): $(OBJS)
		$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

clean:
		rm -f ${OBJS}

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re