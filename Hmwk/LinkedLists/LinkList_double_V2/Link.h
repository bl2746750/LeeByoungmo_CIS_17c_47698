/* 
 * File:   Link.h
 * Author: Student Byoung Mo Lee
 *
 * Created on October 8, 2019, 11:34 AM
 */

#ifndef LINK_H
#define LINK_H

struct Link{
    int data;
    //Link *prev;
    struct Link *next;
    struct Link *prev;
};


#endif /* LINK_H */