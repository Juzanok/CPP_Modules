# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:34:48 by jkarosas          #+#    #+#              #
#    Updated: 2022/11/24 02:02:38 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= class_template

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRCS		= main.cpp
HEADER		= Array.hpp

OBJDIR		= build/
OBJ_NAME	= $(patsubst %.cpp,%.o,$(SRCS))
OBJS		= $(addprefix $(OBJDIR), $(OBJ_NAME))

all:	$(NAME)

$(NAME):	$(OBJDIR) $(OBJS) $(HEADER)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o:	%.cpp $(HEADER)
				$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
			mkdir build

clean:	
		$(RM) $(OBJDIR)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all