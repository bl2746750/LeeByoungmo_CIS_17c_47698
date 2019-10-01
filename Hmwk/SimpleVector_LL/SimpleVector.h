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
   Link* head;       //First list doesn't have a value like textbook(Gaddis).
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector(){head=nullptr;}
      
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
    Link *nodePtr, *next;
    if(!head){
//        cout << "!head" << endl;
        return 0;
    }
    else{
        nodePtr=head;

        int cnt=1;
        do{
            cnt++;
            nodePtr=nodePtr->ptr;
        }while(nodePtr->ptr);
//        cout << "size()=" << cnt << endl;
        return cnt;  
    }
}

template <class T>
void SimpleVector<T>::pop_front(){
    if(!head) return;
    else{
        Link* front=head;
        front=front->ptr;
        Link *second;
        second=front->ptr;
        delete front;
        head->ptr=second;
    }
}
template <class T>
void SimpleVector<T>::pop_back(){
    if(!head)return;
    Link *nodePtr=head,*end;
        
    do{
        end=nodePtr;
        nodePtr=nodePtr->ptr;
    }while(nodePtr->ptr);
    delete nodePtr;
    end->ptr=0;
}
template <class T>

void SimpleVector<T>::push_front(T val){
//    cout << "0push_front(T val)" << endl;   
//    cout << "list=" << head << endl;
//    cout << "list->data=" << head->data << endl;
//    cout << "list->ptr=" << head->ptr << endl;
    Link* newNode=new Link;
    newNode->data=val;
    
    if(!head){
//        cout << endl << "1" << endl;
//        head=new Link;
//        head=head->ptr;
        head=newNode;
        newNode->ptr=nullptr;
//        cout << "1push_front(T val)" << endl;   
//        cout << "head=" << head << endl;
//        cout << "list->data=" << head->data << endl;
//        cout << "list->ptr=" << head->ptr << endl;
//        cout << "size()=" << size() << endl;
    }
    else{
//        cout << endl << "2" << endl;
        Link* secNode=head;
        newNode->ptr=secNode;
        head=newNode;
//        cout << "2push_front(T val)" << endl;   
//        cout << "list=" << head << endl;
//        cout << "list->data=" << head->data << endl;
//        cout << "list->ptr=" << head->ptr << endl;
//        cout << "size()=" << size() << endl;
    }
//    Link *front=new Link;
//    front->data=val;
//    front->ptr=list;
    
}

template <class T>
void SimpleVector<T>::push_back(T val){
//    cout << "push_back val=" << val << endl;
    Link* newNode=new Link;
    newNode->data=val;
    newNode->ptr=0;
        
    if(!head) {
//        cout << "!head"  << endl;
        head=newNode;
    } else{
//        cout << "head=" << head->data << endl;
        Link *end=head;
        while(end->ptr){end=end->ptr;}
        end->ptr=newNode;    
//        cout << "end=" << end->data << endl;
    }
    
//    cout << "size()=" << size() << endl;
}

template <class T>
void SimpleVector<T>::prntLst(){
    Link *nodePtr;
//    front=new Link;
    nodePtr=head;
    int cnt=0;
//    front->data=list->data;
    cout<<endl;
    while(nodePtr){
        cout <<"["<<cnt<<"]";
        
        cout<<nodePtr->data<<endl;
        nodePtr=nodePtr->ptr;
        cnt++;
    }
    cout<<endl;
    delete nodePtr;  
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
    Link *nextNode=head;
    
    while(nextNode){
        nextNode=head->ptr;
        delete head;
        head=nextNode;
    }
    
    
}
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    //cout << "size()="<<size() << endl;
    head=0;
    //cout << "size()="<<size() << endl;
    int cnt=s;
//    cout << "SimpleVector(int s)" << cnt << endl;
    
    do{
        push_front(cnt--);
//        push_back(--cnt);
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
    head=0;
//    cout << "test, head=" << head << endl;
    Link* nodePtr=obj.head;
    
//    cout << "list = " << list << " obj.list=" << obj.list << endl;
//    cout << "list->data=" << list->data << " obj.list->data=" << obj.list->data << endl;
//    cout << "list->ptr=" << list->ptr << " obj.list->ptr=" << obj.list->ptr << endl;
//    cout << "size()=" << size() << " obj.size()=" << obj.size() << endl;
//    cout << "orig="<<orig<<endl;
//    cout << "list[0]=" << list->data << endl;
    while(nodePtr){
        
//        cout << "nodePtr->data="<<nodePtr->data<<endl;
        push_back(nodePtr->data);
        nodePtr=nodePtr->ptr;
        
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
//    int cnt=0;
    nodePtr=head;
//    while(list){
//        cout << cnt << list->data << endl;
//        list=list->ptr;
//        cnt++;
//    }
//    cout << cnt << endl;
    while(nodePtr){
        nextNode=nodePtr->ptr;
        delete nodePtr;
        nodePtr=nextNode;
//        cout << cnt << endl;
//        cnt++;
        
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
    find=head;
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
    Link* nodePtr = head;
    
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