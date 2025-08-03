#include "Span.hpp"

Span::Span(){
}

Span::Span(unsigned int size): size(size){
}

Span::Span(const Span &s): numbers(s.numbers),size(s.size){
}

Span::~Span(){
}

Span &Span::operator=(const Span &s)
{
    if(this!= &s)
    {
        this->numbers = s.numbers;
        this->size = s.size;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if(numbers.size() >= size)
        throw Span::MoreNumber();
    this->numbers.push_back(n);
}

int Span::shortestSpan()
{
    int num_min;

    if (numbers.size() < 2)
        throw Span::NotEnoughNumber();
    std::vector<int> sortNum = this->numbers;
    std::sort(sortNum.begin(), sortNum.end());
    num_min = INT_MAX;
    for(std::vector<int>::iterator r = sortNum.begin(); r != sortNum.end() - 1; ++r)
    {
        int comp = *(r + 1) - *r;
        if(num_min > comp)
            num_min = comp;
    }
    return num_min;
}

int Span::longestSpan()
{
    int num_max, num_min;

    if (numbers.size() < 2)
        throw Span::NotEnoughNumber();
    num_min = *std::min_element(numbers.begin(), numbers.end());
    num_max = *std::max_element(numbers.begin(), numbers.end());
    return num_max - num_min;
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while(begin != end)
    {
        if(this->numbers.size() >= this->size)
            throw Span::MoreNumber();
        this->numbers.push_back(*begin);
        ++begin;
    }
}
