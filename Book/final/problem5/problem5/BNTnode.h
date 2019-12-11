/* 
 * File:   BNTnode.h
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on May 23, 2019, 9:14 PM
 * Purpose:  A binary tree node
 */

#ifndef BNTNODE_H
#define	BNTNODE_H

#include <string>
using namespace std;

struct BNTnode{
    string data;
    int value;
    struct BNTnode *left;
    struct BNTnode *right;
};

#endif	/* BNTNODE_H */