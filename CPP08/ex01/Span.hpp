#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

class Span
{
    private:
        std::vector<int> numbers;
        unsigned int size;
        class MoreNumber : public std::exception {
            public:
                const char* what() const throw() { return "Trying to add number more then the size"; }
        };
        class NotEnoughNumber : public std::exception {
            public:
                const char* what() const throw() { return "Not Enough Number to find span"; }
        };
    public:
        Span();
        ~Span();
        Span(const Span &s);
        Span &operator=(const Span &s);
        Span(unsigned int n);
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};
