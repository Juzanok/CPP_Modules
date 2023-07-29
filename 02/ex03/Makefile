# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 03:20:30 by jkarosas          #+#    #+#              #
#    Updated: 2022/10/11 17:16:38 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
SRCS = main.cpp Fixed.cpp Point.cpp bsp.cpp

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