#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    void addNumber(int number);
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    unsigned int size() const;
    unsigned int maxSize() const;
    class FullContainerException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is already full, cannot add more numbers";
        }
    };
    
    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Cannot find span: need at least 2 numbers";
        }
    };
    
    class TooManyElementsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Cannot add elements: would exceed maximum size";
        }
    };
};
template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    unsigned int elementsToAdd = std::distance(begin, end);
    if (_numbers.size() + elementsToAdd > _maxSize) {
        throw TooManyElementsException();
    }
    _numbers.insert(_numbers.end(), begin, end);
}

#endif