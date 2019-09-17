/* 
 * File:   Triangle.h
 * Author: Dr. Mark E. Lehr
 * Created on January 22nd, 2019, 8:36 PM
 * Purpose:  Specification of a Triangular array from a Row Array
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "RowAray.h"

class Triangle{
    private:
        int szRow;
        int szCol;
        int* col;
        int* indx;
        RowAray **records;
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow(){return szRow;}
        int getSzCol(){return szCol;}
        int* getColNum(){return col;}
        int* getIndx(){return indx;}
        int getData(int,int);
};


#endif	/* TRIANGLE_H */

