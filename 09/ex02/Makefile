NAME		= PmergeMe

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
RM			= rm -rf

SRCS		= main.cpp PmergeMe.cpp
HEADER		= PmergeMe.hpp

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