/* 
 * File:   Triangle.cpp
 * Author: Student Byoung Mo Lee
 * Created on September 17th, 2019, 08:06 AM
 * Purpose: Specification for Triangle object
 */

#include "Triangle.h"
#include <cstdlib>

Triangle::Triangle(int rS){
    szCol=rS;   //same like first assignment
    szRow=rS;
    col=new int [szCol];
    indx=new int [szCol];
    for(int i=0;i<szCol;i++){
        indx[i]=i;
        col[i]=rand()%(szCol-1)+1;
    }
    records=new RowAray* [szRow];
    for(int i=0;i<szRow;i++){
        records[i]=new RowAray(col[i]);  
    }
    
    for(int i=0;i<szCol-1;i++){//Find Smallest for each list
        for(int j=i+1;j<szCol;j++){//Examine each element below top of list
            //Swap
            if(col[indx[i]]>col[indx[j]]){
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
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