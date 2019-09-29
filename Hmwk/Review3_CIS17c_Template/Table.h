/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: Student Byoung Mo Lee
 * Purpose: Template
 * Created on September 28, 2019, 4:16 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int row,int col)const{return columns[row]->getData(col);}
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int r, unsigned int c){
    szRow=r;
    szCol=c;
    columns=new RowAray<T>* [szRow];
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray<T> (szCol);
    }
}

template<class T>
Table<T>::Table(const Table<T> &obj){
    szRow=obj.szRow;
    szCol=obj.szCol;
    columns=new RowAray<T>* [szRow];
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray<T>(szCol);
    }
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            columns[i]->setData(j,obj.getData(i,j));
        }
    }
}

template<class T>
Table<T>::~Table(){
    for(int i=0;i<szRow;i++){
        delete columns[i];
    }
    delete[] columns;    
}

template<class T>
void Table<T>::setData(int row,int col,T val){
    columns[row]->setData(col,val);
}

template<class T>
Table<T> Table<T>::operator+(const Table<T> &right){
    Table temp(right.getSzRow(),right.getSzCol());
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            temp.setData(i,j,columns[i]->getData(j)+right.getData(i,j));
        }
    }
    return temp;
}
#endif /* TABLE_H */

