# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:52:12 by jkarosas          #+#    #+#              #
#    Updated: 2022/10/31 14:49:48 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= polymorphism

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRCS		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
HEADER		= AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp

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