/* 
 * Author: Student Byoung Mo Lee
 * Created on September 19th, 2019, 01:52 AM
 * Purpose:  Abstraction, Operator Overloading, 
 *           Copy Construction and Polymorphism
 */
#include <iostream>
#include "PlusTab.h"
using namespace std;

PlusTab PlusTab::operator+(const PlusTab &right){
    PlusTab temp(right.getSzRow(),right.getSzCol());
    for(int i=0;i<getSzRow();i++){
        for(int j=0;j<getSzCol();j++){
            temp.setData(i,j,columns[i]->getData(j)+right.getData(i,j));
        }
    }
    return temp;
}