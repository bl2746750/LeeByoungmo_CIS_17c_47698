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
   T *aptr;          // To point to the allocated array
   int arraySize;    // Number of elements in the array
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range

public:
   // Default constructor
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration
   SimpleVector(int);
   
   // Copy constructor declaration
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration
   ~SimpleVector();
   
   // Accessor to return the array size
   int size() const
      { return arraySize; }

   // Accessor to return a specific element
   T getElementAt(int position);

   // Overloaded [] operator declaration
   T &operator[](const int &);
   
   void push_front(T);
   void push_back(T);
   T    pop_front();
   T    pop_back();
//   //push_back
//   void pushBack(T);
//   
//   //pop_back
//   void popBack();
//   
//   //push_front
//   void pushFront(T);
//   
//   //pop_front
//   void popFront();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
   arraySize = s;
   // Allocate memory for the array.
   try
   {
      aptr = new T [s];
   }
   catch (bad_alloc)
   {
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
   // Copy the array size.
   arraySize = obj.arraySize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector()
{
   if (arraySize > 0)
      delete [] aptr;
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
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

////push_back
//template <class T>
//void SimpleVector<T>::pushBack(T pushed){
//   // Copy to copySV temporarily
//   SimpleVector<T> copySV(arraySize);
//   for(int count = 0; count < arraySize; count++)
//      *(copySV.aptr + count) = *(aptr + count);
//   
//   //delete the original array
//   delete[] aptr;
//   
//   //increment arraysize
//   arraySize ++;
//    
//   // Allocate memory for the array.
//   aptr = new T [arraySize];
//   if (aptr == 0)
//      memError();
//      
//   // Copy the elements of copy's array.
//   for(int count = 0; count < arraySize-1; count++)
//      *(aptr + count) = *(copySV.aptr + count); 
//
//   *(aptr+arraySize-1)=pushed; 
//}
//
////pop_back
//template <class T>
//void SimpleVector<T>::popBack(){
//   // Copy to copySV temporarily
//   SimpleVector<T> copySV(arraySize);
//   for(int count = 0; count < arraySize; count++)
//      *(copySV.aptr + count) = *(aptr + count);
//   
//   //delete the original array
//   delete[] aptr;
//   
//   //decrement arraysize
//   arraySize --;
//    
//   // Allocate memory for the array.
//   aptr = new T [arraySize];
//   if (aptr == 0)
//      memError();
//      
//   // Copy the elements of copy's array.
//   for(int count = 0; count < arraySize; count++)
//      *(aptr + count) = *(copySV.aptr + count); 
//
//}
//
////push_front
//template <class T>
//void SimpleVector<T>::pushFront(T pushed){
//   // Copy to copySV temporarily
//   SimpleVector<T> copySV(arraySize);
//   for(int count = 0; count < arraySize; count++)
//      *(copySV.aptr + count) = *(aptr + count);
//   
//   //delete the original array
//   delete[] aptr;
//   
//   //increment arraysize
//   arraySize ++;
//    
//   // Allocate memory for the array.
//   aptr = new T [arraySize];
//   if (aptr == 0)
//      memError();
//      
//   // Copy the elements of copy's array.
//   *(aptr)=pushed;
//   for(int count = 1; count < arraySize; count++)
//      *(aptr + count) = *(copySV.aptr + count-1); 
//
//        
//}
//
////pop_front
//template <class T>
//void SimpleVector<T>::popFront(){
//   // Copy to copySV temporarily
//   SimpleVector<T> copySV(arraySize);
//   for(int count = 0; count < arraySize; count++)
//      *(copySV.aptr + count) = *(aptr + count);
//   
//   //delete the original array
//   delete[] aptr;
//   
//   //decrement arraysize
//   arraySize --;
//    
//   // Allocate memory for the array.
//   aptr = new T [arraySize];
//   if (aptr == 0)
//      memError();
//      
//   // Copy the elements of copy's array.
//   for(int count = 0; count < arraySize; count++)
//      *(aptr + count) = *(copySV.aptr + count+1); 
//    
//}
template <class T>
void SimpleVector<T>::push_front(T val){
   // Copy to copySV temporarily
   SimpleVector<T> copySV(arraySize);
   for(int count = 0; count < arraySize; count++)
      *(copySV.aptr + count) = *(aptr + count);
   
   //delete the original array
   delete[] aptr;
   
   // Allocate memory for the array.
   aptr = new T [copySV.size()+1];
   
//   cout << "push_front ArraySize" << copySV.size()+1 << endl;
//   cout << "push_front ArraySize" << arraySize << endl;
   arraySize=copySV.size()+1;
   if (aptr == 0)
      memError();
      
   // Copy the elements of copy's array.
   *(aptr)=val;
   for(int count = 1; count < arraySize; count++)
      *(aptr + count) = *(copySV.aptr + count-1); 
   
//   delete [] copySV;

}

template <class T>
void SimpleVector<T>::push_back(T val){
   // Copy to copySV temporarily
   SimpleVector<T> copySV(arraySize);
   for(int count = 0; count < arraySize; count++)
      *(copySV.aptr + count) = *(aptr + count);
   
   //delete the original array
   delete[] aptr;
       
   // Allocate memory for the array.
   aptr = new T [copySV.size()+1];
   arraySize=copySV.size()+1;
   
   if (aptr == 0)
      memError();
      
   // Copy the elements of copy's array.
   for(int count = 0; count < arraySize-1; count++)
      *(aptr + count) = *(copySV.aptr + count); 

   *(aptr+arraySize-1)=val; 
//   delete [] copySV;
}

template <class T>
T SimpleVector<T>::pop_front(){
   T dummy;
   // Copy to copySV temporarily
   SimpleVector<T> copySV(arraySize);
   for(int count = 0; count < arraySize; count++)
      *(copySV.aptr + count) = *(aptr + count);
   dummy=copySV.getElementAt(0);
   //delete the original array
   delete[] aptr;
   
   // Allocate memory for the array.
   aptr = new T [copySV.size()-1];
   arraySize=copySV.size()-1;
   if (aptr == 0)
      memError();
      
   // Copy the elements of copy's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(copySV.aptr + count+1);  
   
   
//   delete [] copySV;
   
   return dummy;
}

template <class T>
T SimpleVector<T>::pop_back(){
    T dummy;
   // Copy to copySV temporarily
   SimpleVector<T> copySV(arraySize);
      
   for(int count = 0; count < arraySize; count++)
      *(copySV.aptr + count) = *(aptr + count);
   
   dummy=copySV.getElementAt(arraySize-1);
   //delete the original array
   delete[] aptr;
   
   // Allocate memory for the array.
   aptr = new T [copySV.size()-1];
   
   arraySize=copySV.size()-1;
   
   if (aptr == 0)
      memError();
      
   // Copy the elements of copy's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(copySV.aptr + count); 
   
//   delete [] copySV;
   
   return dummy;
}
#endif