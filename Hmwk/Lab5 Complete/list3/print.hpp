/* 
 * File:   print.hpp
 * Author: Student Byoung Mo Lee
 * Purpose: learning forwardlist find(p216)
 * Created on October 9, 2019, 10:38 PM
 */

#ifndef PRINT_HPP
#define PRINT_HPP
#include <iostream>
#include <string>

// PRINT_ELEMENTS()
// - prints optional string optstr followed by
// - all elements of the collection coll
// - in one line, separated by spaces
template <typename T>
inline void PRINT_ELEMENTS (const T& coll,
                            const std::string& optstr="")
{
    std::cout << optstr;
    for (const auto&  elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}
#endif /* PRINT_HPP */

