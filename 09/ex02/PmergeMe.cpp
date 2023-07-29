#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }
PmergeMe::PmergeMe(const PmergeMe &copy) { *this = copy; }
PmergeMe::~PmergeMe(void) { }

PmergeMe::PmergeMe(int argc, char **argv, int flag)
{
    gettimeofday(&this->start_time, 0);
    if (flag == 0) {
        for (int i = 1; i < argc; i++)
            vector.push_back(atof(argv[i])); 
    }
    else {
        for (int i = 1; i < argc; i++)
            deque.push_back(atof(argv[i]));
    }
    run_sorting(flag);
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &copy)
{
    this->vector = copy.vector;
    this->deque = copy.deque;
    return (*this);
}

void    PmergeMe::run_sorting(int flag)
{
    long            sec;
    long            micro;
    long double     elapsed;
    size_t          size;
    std::string     type;
    struct timeval  end_time;

    if (flag == 0)
    {
        size = vector.size();
        type = "std::vector";
        std::cout << std::setw(10) << std::left << "Before: ";
        print_content();
        sort(vector, 0, vector.size() - 1);
        gettimeofday(&end_time, 0);
        std::cout << std::setw(10) << std::left << "After: ";
        print_content();
    }
    else
    {
        size = deque.size();
        type = "std::deque";
        sort(deque, 0, deque.size() - 1);
        gettimeofday(&end_time, 0);
    }
    sec = end_time.tv_sec - start_time.tv_sec;
    micro = end_time.tv_usec - start_time.tv_usec;
    elapsed = (sec * 1000000 + micro);
    std::cout << "Time to process a range of " << size << " elements with " << type << " : " << elapsed << " μs" << std::endl;
}

void    PmergeMe::print_content(void)
{
    size_t i = 0;
    while (i < vector.size())
    {
        std::cout << vector[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void    PmergeMe::sort(std::vector<int> &vec, int start, int end)
{
    if (end - start > 5)
    {
        int mid = (start + end) / 2;
        sort(vec, start, mid);
        sort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
    else
        insertionSort(vec, start, end);
}

void    PmergeMe::merge(std::vector<int> &vec, int start, int mid, int end)
{
    std::vector<int> LA = copyVecRange(vec, start, mid + 1);
    std::vector<int> RA = copyVecRange(vec, mid + 1, end + 1);
    int n1 = LA.size();
    int n2 = RA.size();
    int RIDX = 0;
    int LIDX = 0;
    for (int i = start; i < end + 1; i++) {
        if (RIDX == n2) {
            vec[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            vec[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            vec[i] = LA[LIDX];
            LIDX++;
        } else {
            vec[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void    PmergeMe::insertionSort(std::vector<int> &vec, int start, int end)
{
    for(int i = start; i < end; i++)
    {
        int tmp = vec[i + 1];
        int j = i + 1;
        while (j > start && vec[j - 1] > tmp)
        {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tmp;
    }
}

std::vector<int>    PmergeMe::copyVecRange(std::vector<int> vec, int start, int end)
{
    std::vector<int> copy;

    while (start < end)
    {
        copy.push_back(vec[start]);
        start++;
    }
    return (copy);
}

// Deque SORT
void    PmergeMe::sort(std::deque<int> &vec, int start, int end)
{
    if (end - start > 2)
    {
        int mid = (start + end) / 2;
        sort(vec, start, mid);
        sort(vec, mid + 1, end);
        merge(vec, start, mid, end);
    }
    else
        insertionSort(vec, start, end);
}

void    PmergeMe::merge(std::deque<int> &vec, int start, int mid, int end)
{
    std::deque<int> LA = copyDeqRange(vec, start, mid + 1);
    std::deque<int> RA = copyDeqRange(vec, mid + 1, end + 1);
    int n1 = LA.size();
    int n2 = RA.size();
    int RIDX = 0;
    int LIDX = 0;
    for (int i = start; i < end + 1; i++) {
        if (RIDX == n2) {
            vec[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            vec[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            vec[i] = LA[LIDX];
            LIDX++;
        } else {
            vec[i] = RA[RIDX];
            RIDX++;
        }
    }
}

void    PmergeMe::insertionSort(std::deque<int> &vec, int start, int end)
{
    for(int i = start; i < end; i++)
    {
        int tmp = vec[i + 1];
        int j = i + 1;
        while (j > start && vec[j - 1] > tmp)
        {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = tmp;
    }
}

std::deque<int>    PmergeMe::copyDeqRange(std::deque<int> vec, int start, int end)
{
    std::deque<int> copy;

    while (start < end)
    {
        copy.push_back(vec[start]);
        start++;
    }
    return (copy);
}


// [ FUNCTIONS TO CHECK IF CONTAINERS ARE PROPERLY SORTED ]

void    PmergeMe::check_sort(int flag)
{
    if (flag == 0)
        check_vector(vector);
    else
        check_deque(deque);
}

void    PmergeMe::check_vector(std::vector<int> vec)
{
    size_t i = 0;
    while (i < vec.size() - 1)
    {
        if (vec[i] > vec[i + 1])
        {
            std::cout << RED << "vector sort : KO" << RESET << std::endl;
            return ;
        }
        i++;
    }
    std::cout << GREEN << "vector sort : OK" << RESET << std::endl;
}

void    PmergeMe::check_deque(std::deque<int> deq)
{
    size_t i = 0;
    while (i < deq.size() - 1)
    {
        if (deq[i] > deq[i + 1])
        {
            std::cout << RED << "deque sort  : KO" << RESET << std::endl;
            return ;
        }
        i++;
    }
    std::cout << GREEN << "deque sort  : OK" << RESET << std::endl;
}