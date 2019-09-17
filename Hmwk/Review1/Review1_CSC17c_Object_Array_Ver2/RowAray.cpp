/* 
 * File:   RowAray.cpp
 * Author: Student Byoung Mo Lee
 * Created on September 16th, 2019, 22:39 PM
 * Purpose: Specification for the RowAray
 */

#include "RowAray.h"
#include <cstdlib> //Random function Library

RowAray::RowAray(int s){
    size=s;
    rowData=new int[size];
    for(int i=0;i<size;i++){
        rowData[i]=rand()%90+10;//2 Digit numbers [10-99]
    }
}

RowAray::~RowAray(){
    delete[] rowData;
}



