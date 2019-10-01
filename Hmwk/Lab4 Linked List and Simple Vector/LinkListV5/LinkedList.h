/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: Student Byoung Mo Lee
 *
 * Created on September 26, 2019, 12:52 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
private:    
    struct ListNode{
        int data;
        ListNode *next;
    };
    
    ListNode *head;
public:
    LinkedList(){head=nullptr;}
    ~LinkedList();
    int pop_front();
    int pop_back();
    void push_front(int);
    void push_back(int);
    void prntLst();
    void dstryLst();
};

#endif /* LINKEDLIST_H */