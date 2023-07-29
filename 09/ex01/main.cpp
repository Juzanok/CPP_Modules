#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || !argv[1]) {
        std::cout << "Error" << std::endl;
        return (1);
    }
    RPN calc(argv[1]);
    calc.run_calculations();
    return (0);
}