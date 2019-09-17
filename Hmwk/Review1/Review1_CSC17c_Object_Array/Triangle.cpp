/* 
 * File:   Triangle.cpp
 * Author: Student Byoung Mo Lee
 * Created on September 17th, 2019, 08:06 AM
 * Purpose: Specification for Triangle object
 */

#include "Triangle.h"

Triangle::Triangle(int rS){
    szRow=rS;
    
    records=new RowAray* [szRow];
    for(int i=0;i<szRow;i++){
        records[i]=new RowAray(i+1);  
    }
}

Triangle::~Triangle(){
    for(int i=0;i<szRow;i++){
        records[i]->~RowAray();
    }
    
    delete records;    
}

int Triangle::getData(int r, int c){
    return records[r]->getData(c);
}