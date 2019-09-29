/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleVector.h
 * Author: rcc
 *
 * Created on September 18, 2019, 8:10 PM
 */

// SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector
{
private:
   struct Link{
       T data;
       Link* ptr;
   };
   Link* list;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector(){list->ptr=nullptr;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const;
      
   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   void pop_front();
   void pop_back();
   void push_front(T);
   void push_back(T);
   void prntLst();
   void dstryLst();
  
   
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************
template <class T>
int SimpleVector<T>::size() const{
    Link *front=list;
    int cnt=0;
    while(front){
        cnt++;
        front=front->ptr;
    }
    return cnt;    
}

template <class T>
void SimpleVector<T>::pop_front(){
    
}
template <class T>
void SimpleVector<T>::pop_back(){
    if(!list)return;
    Link *front=list,*back;
    while(front->ptr){
        back=front;
        front=front->ptr;
    }
    delete front;
    back->ptr=0;
}
template <class T>

void SimpleVector<T>::push_front(T val){
    Link *front=new Link;
    Link *nodeptr;
    front->data=val;
    if(!list){
        list->data=front->data;
        list->ptr=nullptr;
    }
    else{
        nodeptr=list;
        list->data=front->data;
        front->ptr=nodeptr;
    }
}

template <class T>
void SimpleVector<T>::push_back(T val){
    Link *back=new Link;
    Link *front=list;
    back->data=val;
    back->ptr=0;
    while(front){
        back=front;
        front=front->ptr;
    }
    Link *end=back;
    end->ptr=back;
}

template <class T>
void SimpleVector<T>::prntLst(){
    Link *front=list;
    cout<<endl;
    while(front){
        cout<<front->data<<endl;
        front=front->ptr;
    }
    cout<<endl;    
}
template <class T>
void SimpleVector<T>::dstryLst(){
    //Link *front=list;
    do{
        Link *temp=list;
        list=list->ptr;
        delete temp;
    }while(list);
    
    list->ptr=0;    
}
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    list=0;
    int cnt=s;
    do{
        push_front(0);
        cnt--;
    }while(cnt);
    
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{

}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    dstryLst();
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    Link* find;
    int cnt=0;
    do{
        find=list->ptr;
        cnt++;
    }while(cnt==sub);
    return list->data;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    Link* find;
    int cnt=0;
    do{
        find=list->ptr;
        cnt++;
    }while(cnt==sub);
    return list->data;
}
#endif