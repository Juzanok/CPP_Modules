#ifndef PMERGEME_HPP
# define PMERGEME_HPP

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
# include <iomanip>
# include <stdlib.h>
# include <vector>
# include <deque>
# include <sys/time.h>

class PmergeMe
{
private:
    std::vector<int>    vector;
    std::deque<int>     deque;
    struct timeval      start_time;


    // Utils
    void    print_content(void);

    // Vector sort
    void    sort(std::vector<int> &vec, int start, int end);
    void    merge(std::vector<int> &vec, int start, int mid, int end);
    void    insertionSort(std::vector<int> &vec, int start, int end);
    std::vector<int>    copyVecRange(std::vector<int> vec, int start, int end);

    void    sort(std::deque<int> &vec, int start, int end);
    void    merge(std::deque<int> &vec, int start, int mid, int end);
    void    insertionSort(std::deque<int> &vec, int start, int end);
    std::deque<int>    copyDeqRange(std::deque<int> vec, int start, int end);

    void    run_sorting(int flag);

    void    check_vector(std::vector<int> vec);
    void    check_deque(std::deque<int> deq);

public:
    PmergeMe(void);
    PmergeMe(int argc, char **argv, int flag);
    PmergeMe(const PmergeMe &copy);
    ~PmergeMe(void);

    PmergeMe	&operator=(const PmergeMe &copy);

    void    check_sort(int flag);
};

#endif