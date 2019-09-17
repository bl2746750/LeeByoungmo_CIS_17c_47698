/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 22nd, 2019, 8:36 PM
 * Purpose:  Dynamic Object Arrays
 */

//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//User Libraries
#include "Table.h"
#include "Triangle.h"

//Global Constants

//Function Prototype
void prntRow(RowAray *,int);
void prntTab(Table *);
void prntTri(Triangle *);
void prntSortedTri(Triangle *);
void prntAry(int *,int);

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables
   int rows=6,cols=8,perLine=cols/2;
   
   //Test out the RowAray
   RowAray row(cols);
    
   //Print the RowAray
   cout<<"The Row Array size = "<<row.getSize()
           <<" printed "<<perLine<<" per Line";

   prntRow(&row,perLine);
   
   //Test out the Table
   Table tab(rows,cols);
   
   //Print the Table
   cout<<"The table size is [row,col] = ["<<rows<<","<<cols<<"]";
   prntTab(&tab);
   
   //Test out the Triangular Table
   Triangle tri(rows);
   
   //Output Located Here
    cout<<"The original Column Matrix"<<endl;
    prntAry(tri.getColNum(),rows);       //Print the original col size for each row
    cout<<endl<<"The sorted Index Array"<<endl;
    prntAry(tri.getIndx(),rows);      //Print the sorted index of column sizes
    cout<<endl<<"The unsorted Triangular Matrx"<<endl;
    cout<<"The triangular table size is [row,row] = ["<<rows<<","<<rows<<"]";
    prntTri(&tri);//Print the Triangular matrix unsorted
    cout<<endl<<"The Triangular Matrix printed by smallest column to largest"<<endl;
    cout<<"The triangular table size is [row,row] = ["<<rows<<","<<rows<<"]";
    prntSortedTri(&tri);//Print the Triangular matrix sorted by col
   
   //Print the Triangular Table
//   cout<<"The triangular table size is [row,row] = ["<<rows<<","<<rows<<"]";
//   prntTri(&tri);

   //Exit Stage Right
   return 0;
}

void prntRow(RowAray *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntTab(Table *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntTri(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getColNum()[row];col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntSortedTri(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getColNum()[a->getIndx()[row]];col++){
            cout<<a->getData(a->getIndx()[row],col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}