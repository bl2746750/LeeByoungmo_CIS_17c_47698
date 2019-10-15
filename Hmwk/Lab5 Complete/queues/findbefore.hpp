/* 
 * File:   findbefore.hpp
 * Author: Student Byoung Mo Lee
 * Purpose: learning forwardlist find(p308)
 * Created on October 10, 2019, 00:05 AM
 */

#ifndef FINDBEFORE_HPP
#define FINDBEFORE_HPP

template <typename InputIterator, typename Tp>
inline InputIterator
find_before (InputIterator first, InputIterator last, const Tp& val)
{
    if (first==last) {
        return first;
    }
    InputIterator next(first);
    ++next;
    while (next!=last && !(*next==val)) {
        ++next;
        ++first;
    }
    return first;
}

template <typename InputIterator, typename Pred>
inline InputIterator
find_before_if (InputIterator first, InputIterator last, Pred pred)
{
    if (first==last) {
        return first;
    }
    InputIterator next(first);
    ++next;
    while (next!=last && !pred(*next)) {
        ++next;
        ++first;
    }
    return first;
}

#endif /* FINDBEFORE_HPP */

