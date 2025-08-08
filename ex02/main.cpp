#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

void testBasicStackOperations() {
    std::cout << "=== Testing Basic Stack Operations ===" << std::endl;
    
    MutantStack<int> mstack;
    std::cout << "Empty stack size: " << mstack.size() << std::endl;
    std::cout << "Empty stack is empty: " << (mstack.empty() ? "true" : "false") << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top after pushing 5, 17: " << mstack.top() << std::endl;
    std::cout << "Size after pushing 2 elements: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "Top after popping: " << mstack.top() << std::endl;
    std::cout << "Size after popping: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << "Final size: " << mstack.size() << std::endl;
    std::cout << std::endl;
}

void testIterators() {
    std::cout << "=== Testing Iterator Functionality ===" << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i) {
        mstack.push(i * 10);
    }
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    const MutantStack<int>& const_stack = mstack;
    std::cout << "Const forward iteration: ";
    for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Const reverse iteration: ";
    for (MutantStack<int>::const_reverse_iterator it = const_stack.rbegin(); it != const_stack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void testCopyConstructorAndAssignment() {
    std::cout << "=== Testing Copy Constructor and Assignment ===" << std::endl;
    
    MutantStack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    MutantStack<int> copied(original);
    std::cout << "Original size: " << original.size() << ", Copied size: " << copied.size() << std::endl;
    std::cout << "Original top: " << original.top() << ", Copied top: " << copied.top() << std::endl;
    original.push(4);
    std::cout << "After adding 4 to original - Original size: " << original.size() << ", Copied size: " << copied.size() << std::endl;
    MutantStack<int> assigned;
    assigned.push(99);
    assigned = original;
    std::cout << "Assigned size: " << assigned.size() << ", top: " << assigned.top() << std::endl;
    assigned = assigned;
    std::cout << "After self-assignment - size: " << assigned.size() << ", top: " << assigned.top() << std::endl;
    std::cout << std::endl;
}

void testWithDifferentContainers() {
    std::cout << "=== Testing with Different Container Types ===" << std::endl;
    MutantStack<int, std::vector<int> > vector_stack;
    vector_stack.push(10);
    vector_stack.push(20);
    vector_stack.push(30);
    
    std::cout << "Vector-based stack: ";
    for (MutantStack<int, std::vector<int> >::iterator it = vector_stack.begin(); 
         it != vector_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    MutantStack<std::string> string_stack;
    string_stack.push("Hello");
    string_stack.push("World");
    string_stack.push("!");
    
    std::cout << "String stack: ";
    for (MutantStack<std::string>::iterator it = string_stack.begin(); 
         it != string_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void testSTLAlgorithms() {
    std::cout << "=== Testing STL Algorithm Compatibility ===" << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 5; i >= 1; --i) {
        mstack.push(i);
    }
    
    std::cout << "Before sorting: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::sort(mstack.begin(), mstack.end());
    
    std::cout << "After sorting: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 3);
    if (found != mstack.end()) {
        std::cout << "Found element 3 at position: " << std::distance(mstack.begin(), found) << std::endl;
    }
    std::cout << std::endl;
}

void compareWithList() {
    std::cout << "=== Comparing MutantStack with std::list ===" << std::endl;
    
    MutantStack<int> mstack;
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i) {
        mstack.push(i);
        lst.push_back(i);
    }
    
    std::cout << "MutantStack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "std::list:   ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "MutantStack size: " << mstack.size() << ", list size: " << lst.size() << std::endl;
    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "=== Testing Edge Cases ===" << std::endl;
    MutantStack<int> single;
    single.push(42);
    std::cout << "Single element - begin == end-1: " << 
        (single.begin() == --single.end() ? "true" : "false") << std::endl;
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    
    MutantStack<int>::iterator it1 = mstack.begin();
    MutantStack<int>::iterator it2 = mstack.begin();
    std::cout << "Iterator equality test: " << (it1 == it2 ? "true" : "false") << std::endl;
    
    ++it1;
    std::cout << "After increment - iterators equal: " << (it1 == it2 ? "true" : "false") << std::endl;
    MutantStack<int> large;
    for (int i = 0; i < 1000; ++i) {
        large.push(i);
    }
    std::cout << "Large stack size: " << large.size() << std::endl;
    std::cout << "Large stack first element: " << *large.begin() << std::endl;
    std::cout << "Large stack last element: " << *(--large.end()) << std::endl;
    std::cout << std::endl;
}

int main() {
    std::cout << "MutantStack Test Suite" << std::endl;
    std::cout << "======================" << std::endl << std::endl;
    
    testBasicStackOperations();
    testIterators();
    testCopyConstructorAndAssignment();
    testWithDifferentContainers();
    testSTLAlgorithms();
    compareWithList();
    testEdgeCases();
    
    std::cout << "All tests completed successfully!" << std::endl;
    
    return 0;
}