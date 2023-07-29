#ifndef RPN_HPP
# define RPN_HPP

# define RESET          "\033[0m"
# define GREY           "\033[0m\033[90m"
# define RED            "\033[0m\033[91m"
# define GREEN          "\033[0m\033[92m"
# define YELLOW         "\033[0m\033[93m"
# define BLUE           "\033[0m\033[94m"
# define MAGENTA        "\033[0m\033[95m"
# define CYAN           "\033[0m\033[96m"
# define WHITE          "\033[0m\033[97m"

# include <iostream>
# include <stack>
# include <stdlib.h>
# include <cctype>

class RPN
{
private:
    std::string         expresion;
    std::stack<double>  stack;

    std::string find_next(size_t *pos);
    int check_element(std::string element);

public:

    RPN(void);
    RPN(std::string expresion);
    RPN(const RPN &copy);
    ~RPN(void);

    RPN	&operator=(const RPN &copy);

    void        run_calculations();
};

#endif