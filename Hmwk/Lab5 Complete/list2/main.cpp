/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Purpose: learning forwardlist find(p307)
 * Created on October 9, 2019, 10:34 PM
 */

#include <forward_list>
#include <iterator>  //p443
#include "print.hpp"
using namespace std;

int main()
{
    forward_list<int> list = { 1, 2, 3, 4, 5, 97, 98, 99 };

    // find the position before the first even element
//    auto posBefore = list.before_begin();
//    for (auto pos=list.begin(); pos!=list.end(); ++pos, ++posBefore) {
//        if (*pos % 2 == 0) {
//            break;  // element found
//        }
//    }
    
    //alternative way with iterator
    auto posBefore = list.before_begin();
    for(;next(posBefore)!=list.end();++posBefore){
        if(*next(posBefore)%2==0){
            break;
        }
    }

    // and insert a new element in front of the first even element
    list.insert_after(posBefore,42);
    PRINT_ELEMENTS(list);
}