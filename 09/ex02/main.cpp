#include "PmergeMe.hpp"

static int    check_arg(int argc, char **argv)
{
    std::string str;
    int num;
    int i = 1;

    if (argc == 1)
        return (1);
    while (i < argc)
    {
        str = argv[i];
        if (str.find_first_not_of("0123456789") != std::string::npos)
            return (1);
        num = atof(argv[i]);
        if (num < 0)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (check_arg(argc, argv))
    {
        std::cout << "Error : invalid input" << std::endl;
        return (1);
    }
    PmergeMe vector(argc, argv, 0);
    PmergeMe deque(argc, argv, 1);
    vector.check_sort(0);
    deque.check_sort(1);
    return (0);
}