#pragma once

#include <iostream> 
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <climits>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::string av;
        std::vector<int> vec_num;
        std::deque<int> deque_num;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &s);
        PmergeMe &operator=(const PmergeMe &s);
        PmergeMe(int ac, char **av);
        int check();
        void sort();
};
