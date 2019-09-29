/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.h
 * Author: Student Byoung Mo Lee
 * Purpose: Template
 * Created on September 28, 2019, 4:12 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template<class T>
RowAray<T>::RowAray(int s){
    size=s;
    rowData=new T [size];
    for(int i=0;i<size;i++){
        rowData[i]=rand()%90+10;
    }
}

template<class T>
RowAray<T>::~RowAray(){
    delete[] rowData;
}

template<class T>
void RowAray<T>::setData(int r, T val){
    rowData[r]=val;
}


#endif /* ROWARAY_H */

