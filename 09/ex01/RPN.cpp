#include "RPN.hpp"

RPN::RPN(void): expresion("") { }
RPN::RPN(std::string expresion): expresion(expresion) { }
RPN::RPN(const RPN &copy) { *this = copy; }
RPN::~RPN(void) { }

RPN	&RPN::operator=(const RPN &copy)
{
    this->expresion = copy.expresion;
    this->stack = copy.stack;
    return (*this);
}

void    RPN::run_calculations()
{
    std::string element;
    double      first;
    double      second;
    size_t      pos = 0;

    while (pos < expresion.length())
    {
        element = find_next(&pos);
        if (check_element(element) < 0)
        {
            std::cout << "Error" << std::endl;
            return ;
        }
        else if (check_element(element) == 0)
            stack.push(atof(element.c_str()));
        else if (check_element(element) == 1)
        {
            if (stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return ;
            }
            second = stack.top();
            stack.pop();
            first = stack.top();
            stack.pop();
            if (element[0] == '+')
                stack.push(first + second);
            else if (element[0] == '-')
                stack.push(first - second);
            else if (element[0] == '*')
                stack.push(first * second);
            else if (element[0] == '/')
                stack.push(first / second);
        }
    }
    if (stack.size() != 1)
    {
        std::cout << "Error" << std::endl;
        return ;
    }
    std::cout << stack.top() << std::endl;
}

std::string RPN::find_next(size_t *pos)
{
    size_t start;
    size_t end;

    start = expresion.find_first_not_of(" \r\t\b\f", *pos);
    if (start == std::string::npos)
        return ("");
    end = expresion.find_first_of(" \r\t\b\f", start);
    *pos = end;
    return (expresion.substr(start, end - start));
}

int RPN::check_element(std::string element)
{
    if (element.length() > 2)
        return (-1);
    if (element.length() == 2)
    {
        if (element[0] == '-' || isdigit(element[1]))
            return (0);
         return (-1);
    }
    if (element.length() == 1)
    {
        if (isdigit(element[0]))
            return (0);
        else if (element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/')
            return (1);
    }
    return (-1);
}
