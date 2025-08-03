#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &s) : av(s.av), vec_num(s.vec_num),  deque_num(s.deque_num){
}

PmergeMe &PmergeMe::operator=(const PmergeMe &s){
    if(this != &s)
    {
        this->av = s.av;
        this->vec_num = s.vec_num;
        this->deque_num = s.deque_num;
    }
    return *this;
}

PmergeMe::PmergeMe(int ac, char **av)
{
    std::string joined;
    if (ac > 1)
    {
        for (int i = 1; i < ac; ++i)
        {
            joined += av[i];
            if (i != ac - 1)
                joined += " ";
    }
    }
    this->av = joined;
}

int PmergeMe::check()
{
    for(unsigned int i = 0; i < this->av.size();i++)
    {
        if(!std::isdigit(av[i]) && !std::isspace(av[i]))
            return 0;
    }
    return 1;   
}

void binaryInsert(std::deque<int>& deque, int value) 
{
    std::deque<int>::iterator it = std::lower_bound(deque.begin(), deque.end(), value);
    deque.insert(it, value);
}

std::deque<int> generateJacobsthalUpTod(int n) 
{
    std::deque<int> seq;
    seq.push_back(1);

    while (seq[seq.size() - 1] < n) 
    {
        int prev = 0;
        if (seq.size() >= 2)
            prev = seq[seq.size() - 2];

        int next = seq[seq.size() - 1] + 2 * prev;
        seq.push_back(next);
    }
    return seq;
}

void sort_deque(std::deque<int> &vec_num)
{
    if (vec_num.size() <= 1)
        return;
    std::deque<std::pair<int,int> > pairs;

    int leftover;
    bool hasLeftover = false;
    if(vec_num.size() % 2 != 0)
    {
        leftover = vec_num[vec_num.size() - 1];
        hasLeftover = true;
    }
    for(unsigned int i = 0; i + 1  < vec_num.size() ; i +=  2)
    {
        int first = vec_num[i];
        int second = vec_num[i+1];

        if(first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    std::deque<int> small, big;

    for(std::deque<std::pair<int,int> >::iterator  it = pairs.begin(); it != pairs.end(); it++)
        small.push_back(it->first);
    
    for(std::deque<std::pair<int,int> >::iterator  it = pairs.begin(); it != pairs.end(); it++)
        big.push_back(it->second);

    sort_deque(big);
    std::deque<int> main_chain = big;

    std::deque<int> jacob_order = generateJacobsthalUpTod(static_cast<int>(small.size()));
    std::deque<bool> inserted(small.size(), false);

    for (int j = static_cast<int>(jacob_order.size()) - 1; j >= 0; --j) 
    {
        int idx = jacob_order[j] - 1;
        if (idx >= 0 && idx < static_cast<int>(small.size()) && inserted[idx] == false) 
        {
            binaryInsert(main_chain, small[idx]);
            inserted[idx] = true;
        }
    }
    for (std::size_t k = 0; k < small.size(); ++k) 
    {
        if (inserted[k] == false)
            binaryInsert(main_chain, small[k]);
    }

    if (hasLeftover == true)
        binaryInsert(main_chain, leftover);

    vec_num = main_chain;
}

void binaryInsert(std::vector<int>& vec, int value) 
{
    std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

std::vector<int> generateJacobsthalUpTo(int n) 
{
    std::vector<int> seq;
    seq.push_back(1);

    while (seq[seq.size() - 1] < n) 
    {
        int prev = 0;
        if (seq.size() >= 2)
            prev = seq[seq.size() - 2];
        int next = seq[seq.size() - 1] + 2 * prev;
        seq.push_back(next);
    }
    return seq;
}

void sort_vector(std::vector<int> &vec_num)
{
    if (vec_num.size() <= 1)
        return ;
    std::vector< std::pair<int,int> > pairs;

    int leftover;
    bool hasLeftover = false;
    if(vec_num.size() % 2 != 0)
    {
        leftover = vec_num[vec_num.size() - 1];
        hasLeftover = true;
    }
    for(unsigned int i = 0; i + 1  < vec_num.size() ; i +=  2)
    {
        int first = vec_num[i];
        int second = vec_num[i+1];

        if(first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }
    std::vector<int> small, big;

    for(std::vector<std::pair<int,int> >::iterator  it = pairs.begin(); it != pairs.end(); it++)
        small.push_back(it->first);

    for(std::vector<std::pair<int,int> >::iterator  it = pairs.begin(); it != pairs.end(); it++)
        big.push_back(it->second);
    
    sort_vector(big);
    std::vector<int> main_chain = big;

    std::vector<int> jacob_order = generateJacobsthalUpTo(static_cast<int>(small.size()));
    std::vector<bool> inserted(small.size(), false);

    for (int j = static_cast<int>(jacob_order.size()) - 1; j >= 0; --j) 
    {
        int idx = jacob_order[j] - 1;
        if (idx >= 0 && idx < static_cast<int>(small.size()) && inserted[idx] == false) 
        {
            binaryInsert(main_chain, small[idx]);
            inserted[idx] = true;
        }
    }

    for (std::size_t k = 0; k < small.size(); ++k) 
    {
        if (inserted[k] == false)
            binaryInsert(main_chain, small[k]);
    }

    if (hasLeftover == true)
        binaryInsert(main_chain, leftover);

    vec_num = main_chain;
}

void PmergeMe::sort()
{
    int num;
    if(this->check() == 0 || this->av.find_first_not_of(' ') == std::string::npos)
    {
        std::cerr <<"Error : Invalid or empty input" << std::endl;
        return ;
    }
    std::stringstream ss(this->av);
    std::string token;
    while(ss >> token)
    {
        if(token.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr<< "Error: Invlaid arguments" << std::endl;
            return ;
        }
        if (token.length() > 1 && token[0] == '0') 
        {
            std::cerr << "Error: Leading zeros are not allowed in '" << token << "'" << std::endl;
            return;
        }
        try
        {
            char* end;
            long result = std::strtol(token.c_str(), &end, 10);

            if (*end != '\0') 
            {
                std::cerr << "Error: invalid integer in '" << token << "'" << std::endl;
                return;
            }
            if(result > INT_MAX || result  == 0)
            {
                std::cerr << "Error: invalid integer in '" << token << "'" << std::endl;
                return ;
            }
            num = static_cast<int>(result);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return ;
        }
        this->vec_num.push_back(num);
        this->deque_num.push_back(num);
    }
    if(vec_num.size() < 2 || deque_num.size() < 2)
    {
        std::cerr << "Error: Not enough numbers" << std::endl;
        return ;
    }
    std::cout<<"Before: ";
    for(unsigned int i = 0; i < vec_num.size(); i++)
    {
        if(i == vec_num.size() - 1)
        {
            std::cout << vec_num[i] << std::endl;
            break ;
        }
        std::cout << vec_num[i] << " ";
    }
    struct timeval start_vec, end_vec;

    gettimeofday(&start_vec, NULL);
    sort_vector(vec_num);
    gettimeofday(&end_vec, NULL);

    struct timeval start_deque, end_deque;

    gettimeofday(&start_deque, NULL);
    sort_deque(deque_num);
    gettimeofday(&end_deque, NULL);

    std::cout<<"After: ";
    for(unsigned int i = 0; i < vec_num.size(); i++)
    {
        if(i == vec_num.size() - 1)
        {
            std::cout << vec_num[i] << std::endl;
            break ;
        }
        std::cout << vec_num[i] << " ";
    }
    double vec_time = (end_vec.tv_sec - start_vec.tv_sec) * 1000000 + (end_vec.tv_usec - start_vec.tv_usec);
    double deque_time = (end_deque.tv_sec - start_deque.tv_sec) * 1000000 + (end_deque.tv_usec - start_deque.tv_usec);

    std::cout << "Time to process a range of " << vec_num.size() << " elements with std::[..] : "  << std::fixed << std::setprecision(5) << vec_time << "us" << std::endl;
    std::cout << "Time to process a range of " << deque_num.size() << " elements with std::[..] : "  << std::fixed << std::setprecision(5) << deque_time << "us" << std::endl;
}
