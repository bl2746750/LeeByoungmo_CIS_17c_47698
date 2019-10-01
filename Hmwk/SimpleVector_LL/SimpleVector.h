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
    do{
        cnt++;
        front=front->ptr;
    }while(front);
//    cout << "size()=" << cnt-1 << endl;
    return cnt;    
}

template <class T>
void SimpleVector<T>::pop_front(){
    if(!list) return;
    Link *front=list->ptr;
    delete list;
    list=front;
}
template <class T>
void SimpleVector<T>::pop_back(){
    if(!list)return;
    Link *front=list;
    Link *back;
    
    do{
        back=front;
        front=front->ptr;
    }while(front->ptr);
    front=0;
    back->ptr=0;
}
template <class T>

void SimpleVector<T>::push_front(T val){
//    cout << "push_front(T val)" << endl;   
//    cout << "list=" << this->list << endl;
//    cout << "list->data=" << this->list->data << endl;
//    cout << "list->ptr=" << this->list->ptr << endl;
    
    if(!list){
        list=new Link;
        list->data=val;
        list->ptr=nullptr;
    }
    else{
        Link * secNode=new Link;
        secNode=list;
        secNode=secNode->ptr;
        list->data=val;
        list->ptr=secNode;
    }
//    Link *front=new Link;
//    front->data=val;
//    front->ptr=list;
    
}

template <class T>
void SimpleVector<T>::push_back(T val){
    cout << "push_back val=" << val << endl;
    if(!list) {
        list=new Link;
        list->data=val;
        list->ptr=0;
    } else{
        Link *back=new Link;
        Link *front=list;
        Link *end;
        back->data=val;
        back->ptr=0;
        while(front){
            end=front;
            front=front->ptr;
        }
        end->ptr=back;    
    }
    
    cout << "size()=" << size() << endl;
}

template <class T>
void SimpleVector<T>::prntLst(){
    Link *front;
//    front=new Link;
    front=list;
    int cnt=0;
//    front->data=list->data;
    cout<<endl;
    while(front){
        cout <<"["<<cnt<<"]";
        cout<<front->data<<endl;
        front=front->ptr;
        cnt++;
    };
    cout<<endl;
    delete front;  //problem: 0 come out at last
//    int perLine=10;
//    cout<<endl;
//    
//    
//    if(size()){
//        for(int i=0;i<size();i++){
//            cout<<getElementAt(i)<<" ";
//            if(i%perLine==(perLine-1))cout<<endl;
//        } // problem with destroyed list
//    }
//    
//    cout<<endl;
}
template <class T>
void SimpleVector<T>::dstryLst(){
    Link *nextNode;
    
    while(list){
        nextNode=list->ptr;
        delete list;
        list=nextNode;
    }
    
}
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    //cout << "size()="<<size() << endl;
    //list=new Link;
    //cout << "size()="<<size() << endl;
    int cnt=s;
//    cout << "SimpleVector(int s)" << cnt << endl;
    
    do{
        push_front(cnt--);
//        push_back(cnt--);
//        cout << "SimpleVector(int s)" << cnt << " " << list->data << endl;
    }while(cnt);
    
//    while(list){
//        cout << cnt << " " << list->data << endl;
//        list=list->ptr;
//        cnt++;
//    }
    
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    list=new Link;
    Link* next=obj.list;
    list->data=obj.list->data;
//    cout << "list = " << list << " obj.list=" << obj.list << endl;
//    cout << "list->data=" << list->data << " obj.list->data=" << obj.list->data << endl;
//    cout << "list->ptr=" << list->ptr << " obj.list->ptr=" << obj.list->ptr << endl;
//    cout << "size()=" << size() << " obj.size()=" << obj.size() << endl;
    
//    cout << "list[0]=" << list->data << endl;
    while(next->ptr){
        next=next->ptr;
        push_back(next->data);
        
    }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
    Link *nextNode;
    Link *nodePtr;
    int cnt=0;
    nodePtr=list;
//    while(list){
//        cout << cnt << list->data << endl;
//        list=list->ptr;
//        cnt++;
//    }
//    cout << cnt << endl;
    while(nodePtr!=nullptr){
        nextNode=nodePtr->ptr;
        delete nodePtr;
        nodePtr=nextNode;
//        cout << cnt << endl;
        cnt++;
        
    }
    
    
    
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
    int cnt=sub;
    find=list;
    while(cnt){
        find=find->ptr;
        cnt--;
    }
    return find->data;
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if(sub<0 || sub>=size()) {
        cout << "Error: Subscript out of range.\n";
        exit(0);
    }
    int cnt=sub;
    Link* nodePtr;
    
    nodePtr=list;
    while(cnt){
        nodePtr=nodePtr->ptr;
        cnt--;
    }
    
//    newNode->data=list->data;
//    newNode->ptr=list->ptr;
//    
//    cout << "&sub=" << sub << "list["<<sub<<"]=" << nodePtr << endl;
//    cout << "size="<<size()<<endl;
//    return newNode->data;
    return nodePtr->data;
    
}
#endif