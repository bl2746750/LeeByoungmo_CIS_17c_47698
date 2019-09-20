/* 
 * Author: Student Byoung Mo Lee
 * Created on September 19th, 2019, 11:12 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 */

#include "Table.h"

Table::Table(unsigned int rS,unsigned int cS){
    szRow=rS;
    szCol=cS;
    columns=new RowAray* [szRow];
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray(szCol);
    }
}

Table::Table(const Table &obj){
    szRow=obj.szRow;
    szCol=obj.szCol;
    columns=new RowAray* [szRow];
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray(szCol);
    }
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            columns[i]->setData(j,obj.getData(i,j));
        }
    }
}
Table::~Table(){
    for(int i=0;i<szRow;i++){
        delete columns[i];
    }
    delete[] columns;
}
int Table::getData(int row,int col)const{
    return columns[row]->getData(col);
}
void Table::setData(int row,int col,int num){
    columns[row]->setData(col,num);
}