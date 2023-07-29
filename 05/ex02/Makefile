# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 15:34:55 by jkarosas          #+#    #+#              #
#    Updated: 2022/11/07 13:59:19 by jkarosas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bureaucrat

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

SRCS		= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HEADER		= Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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
