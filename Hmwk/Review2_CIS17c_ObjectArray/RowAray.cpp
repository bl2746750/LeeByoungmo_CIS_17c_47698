/* 
 * Author: Student Byoung Mo Lee
 * Created on September 19th, 2019, 10:56 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 */

#include <cstdlib>
#include "RowAray.h"

RowAray::RowAray(unsigned int s){
    size=s;
    rowData=new int [size];
    for(int i=0;i<size;i++){
        rowData[i]=rand()%90+10;
    }
}

RowAray::~RowAray(){
    delete[] rowData;
}

void RowAray::setData(int col,int num){
    rowData[col]=num;
}