/* 
 * File:   stack.hpp
 * Author: Student Byoung Mo Lee
 * Purpose: User Defined Stack Class(p635)
 * Created on October 10, 2019, 00:34 AM
 */

#ifndef STACK_HPP
#define STACK_HPP
/* ************************************************************
 *  Stack.hpp
 *   - safer and more convenient stack class
 * ************************************************************/

#include <deque>
#include <exception>

template <typename T>
class Stack {
  protected:
    std::deque<T> c;        // container for the elements

  public:
    // exception class for pop() and top() with empty stack
    class ReadEmptyStack : public std::exception {
      public:
        virtual const char* what() const throw() {
            return "read empty stack";
        }
    };
  
    // number of elements
    typename std::deque<T>::size_type size() const {
        return c.size();
    }

    // is stack empty?
    bool empty() const {
        return c.empty();
    }

    // push element into the stack
    void push (const T& elem) {
        c.push_back(elem);
    }

    // pop element out of the stack and return its value
    T pop () {
        if (c.empty()) {
            throw ReadEmptyStack();
        }
        T elem(c.back());
        c.pop_back();
        return elem;
    }

    // return value of next element
    T& top () {
        if (c.empty()) {
            throw ReadEmptyStack();
        }
        return c.back();
    }
};

#endif /* STACK_HPP */

