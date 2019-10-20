/* 
 * File:   Templates.h
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 09:50 AM
 * Purpose: Templates
 * 
 */

#ifndef TEMPLATES_H
#define TEMPLATES_H

#include "Card.h"

using namespace std;


template <class T>
void swapVars(T &var1, T &var2){
    T temp;
    
    temp=var1;
    var1=var2;
    var2=temp;
}

template <class T>
void selectionSortVar(T* var,int begin,int size){
    T maxValue;
    int minIndex;
    int end=begin+size;
    for(int start=begin;start<end-1;start++){
        minIndex=start;
        maxValue=var[start];
        for(int index=start+1;index<end;index++){
            if(var[index]>maxValue){
                maxValue=var[index];
                minIndex=index;
            }
        }
        swap(var[minIndex],var[start]);
    }
}

void selectionSort(int** array,int col,int begin, int size){
    int maxIndex, maxValue;
    int end=begin+size;
    for(int start=begin;start<end-1;start++){
        maxIndex=start;
        maxValue=array[start][col];
        for(int index=start+1;index<end;index++){
            if(array[index][col]>maxValue){
                maxValue=array[index][col];
                maxIndex=index;
            }
        }
        swapVars(array[maxIndex][1],array[start][1]);
        swapVars(array[maxIndex][0],array[start][0]);
    }
}

#endif /* TEMPLATES_H */