/* 
 * File:   Table.cpp
 * Author: Student Byoung Mo Lee
 * Created on September 16th, 2019, 22:49 PM
 * Purpose: Specification for the 2D table object
 */

#include "Table.h"

Table::Table(int rS, int cS ){
    szRow=rS;
    szCol=cS;
    
    records=new RowAray* [szRow];
    for(int i=0;i<szRow;i++){
        records[i]=new RowAray(szCol);
    }
}

Table::~Table(){
    for(int i=0;i<szRow;i++){
        records[i]->~RowAray();
    }
    
    delete records;
}

int Table::getData(int r, int c){
    return records[r]->getData(c);
}
