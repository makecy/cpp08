#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

void testVector() {
    std::cout << "\n=== Testing with std::vector ===" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(42);
    vec.push_back(7);
    vec.push_back(99);
    
    std::cout << "Vector: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    try {
        std::vector<int>::iterator result = easyfind(vec, 42);
        std::cout << "Found 42: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        easyfind(vec, 100);
        std::cout << "Found 100" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Searching for 100: " << e.what() << std::endl;
    }
}

void testList() {
    std::cout << "\n=== Testing with std::list ===" << std::endl;
    
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    try {
        std::list<int>::iterator result = easyfind(lst, 20);
        std::cout << "Found 20: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        easyfind(lst, 50);
        std::cout << "Found 50" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Searching for 50: " << e.what() << std::endl;
    }
}

void testEdgeCases() {
    std::cout << "\n=== Testing edge cases ===" << std::endl;
    std::vector<int> emptyVec;
    try {
        easyfind(emptyVec, 1);
        std::cout << "Found 1 in empty vector" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Empty container: " << e.what() << std::endl;
    }
    const std::vector<int> constVec(1, 42);
    try {
        std::vector<int>::const_iterator result = easyfind(constVec, 42);
        std::cout << "Found in const container: " << *result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error in const container: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "=== easyfind Function Tests ===" << std::endl;
    
    testVector();
    testList();
    testEdgeCases();
    
    std::cout << "\n=== Tests completed ===" << std::endl;
    return 0;
}