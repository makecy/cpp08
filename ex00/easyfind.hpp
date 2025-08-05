#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>

template<typename T>
typename T::iterator easyfind(T& container, int value);

template<typename T>
typename T::const_iterator easyfind(const T& container, int value);

class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Value not found in container";
    }
};

#include "easyfind.tpp"

#endif