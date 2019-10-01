/* 
 * File:   Link.cpp
 * Author: Student Byoung Mo Lee
 * Date:   Sept 26th, 2019, 12:52PM
 * Purpose:Exploration of a Linked List
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::~LinkedList(){
    ListNode *nodePtr;
    ListNode *nextNode;
    
    nodePtr=head;
    
    while(nodePtr != nullptr){
        nextNode=nodePtr->next;
        delete nodePtr;
        nodePtr=nextNode;
    }
}

int LinkedList::pop_front(){
    ListNode *nodePtr;
    int frontNum=0;
    
    if(!head) return 0;
    else{
        nodePtr=head->next;
        head=nodePtr->next;
        frontNum=nodePtr->data;
        delete nodePtr;
        
        return frontNum;
    }
}