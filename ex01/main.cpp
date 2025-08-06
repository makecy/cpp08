#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void testProvidedExample() {
    std::cout << "\n=== Testing provided example ===" << std::endl;
    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Numbers added: 6, 3, 17, 9, 11" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptions() {
    std::cout << "\n=== Testing exceptions ===" << std::endl;
    Span smallSpan(2);
    try {
        smallSpan.addNumber(1);
        smallSpan.addNumber(2);
        std::cout << "Added 2 numbers successfully" << std::endl;
        smallSpan.addNumber(3);  // this should throw
    } catch (const std::exception& e) {
        std::cout << "Exception when adding 3rd number: " << e.what() << std::endl;
    }
    Span emptySpan(5);
    try {
        emptySpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception on empty span: " << e.what() << std::endl;
    }
    Span singleSpan(5);
    singleSpan.addNumber(42);
    try {
        singleSpan.longestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception on single element span: " << e.what() << std::endl;
    }
}

void testRangeAddition() {
    std::cout << "\n=== Testing range addition ===" << std::endl;
    Span span(10);
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(9);
    span.addNumbers(vec.begin(), vec.end());
    std::cout << "Added " << vec.size() << " numbers from vector" << std::endl;
    std::cout << "Span size: " << span.size() << "/" << span.maxSize() << std::endl;
    std::list<int> lst;
    lst.push_back(2);
    lst.push_back(8);
    lst.push_back(4);
    span.addNumbers(lst.begin(), lst.end());
    std::cout << "Added " << lst.size() << " numbers from list" << std::endl;
    std::cout << "Span size: " << span.size() << "/" << span.maxSize() << std::endl;
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
    std::vector<int> bigVec(5, 10);
    try {
        span.addNumbers(bigVec.begin(), bigVec.end());  // exceeds capacity
    } catch (const std::exception& e) {
        std::cout << "Exception when adding too many: " << e.what() << std::endl;
    }
}

void testLargeNumbers() {
    std::cout << "\n=== Testing with 15,000 numbers ===" << std::endl;
    const unsigned int SIZE = 15000;
    Span largeSpan(SIZE);
    srand(time(NULL));
    std::vector<int> randomNumbers;
    for (unsigned int i = 0; i < SIZE; i++) {
        randomNumbers.push_back(rand() % 100000);
    }
    std::cout << "Adding " << SIZE << " random numbers..." << std::endl;
    largeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());
    std::cout << "Span filled with " << largeSpan.size() << " numbers" << std::endl;
    std::cout << "Calculating spans..." << std::endl;
    unsigned int shortest = largeSpan.shortestSpan();
    unsigned int longest = largeSpan.longestSpan();
    std::cout << "Shortest span: " << shortest << std::endl;
    std::cout << "Longest span: " << longest << std::endl;
}

void testEdgeCases() {
    std::cout << "\n=== Testing edge cases ===" << std::endl;
    Span negativeSpan(5);
    negativeSpan.addNumber(-10);
    negativeSpan.addNumber(-5);
    negativeSpan.addNumber(0);
    negativeSpan.addNumber(5);
    negativeSpan.addNumber(10);
    std::cout << "With negative numbers (-10, -5, 0, 5, 10):" << std::endl;
    std::cout << "Shortest span: " << negativeSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << negativeSpan.longestSpan() << std::endl;
    Span duplicateSpan(4);
    duplicateSpan.addNumber(5);
    duplicateSpan.addNumber(5);
    duplicateSpan.addNumber(10);
    duplicateSpan.addNumber(10);
    std::cout << "With duplicates (5, 5, 10, 10):" << std::endl;
    std::cout << "Shortest span: " << duplicateSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << duplicateSpan.longestSpan() << std::endl;
}

int main() {
    std::cout << "=== Span Class Tests ===" << std::endl;
    
    try {
        testProvidedExample();
        testExceptions();
        testRangeAddition();
        testLargeNumbers();
        testEdgeCases();
        std::cout << "\n=== All tests completed ===" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}