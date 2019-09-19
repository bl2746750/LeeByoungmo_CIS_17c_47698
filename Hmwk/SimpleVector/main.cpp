/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2019, 7:50 PM
 * Purpose:  To Test and Modify the Simple Vector
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "SimpleVector.h"

//Global Constants

//Function prototypes
void fillVec(SimpleVector<float> &);
void prntVec(SimpleVector<float> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int size=100;
    SimpleVector<float> sv(size);
    
    //Fill the Vector
    fillVec(sv);
    
    //Print the Vector
    prntVec(sv,10);
    
    //Copy the Vector
    SimpleVector<float> copysv(sv);
    
    //Print the Vector
    prntVec(copysv,10);
    
    //push_back the Vector
    sv.pushBack(50);
    
    //Print the Vector
    prntVec(sv,10);
    
    //pop_back the Vector
    sv.popBack();
    
    //Print the Vector
    prntVec(sv,10);
    
    //push_front
    sv.pushFront(50);

    //Print the Vector
    prntVec(sv,10);
    
    //pop_front
    sv.popFront();

    //Print the Vector
    prntVec(sv,10);
    
    return 0;
}

void prntVec(SimpleVector<float> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<float> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=rand()%90+10;
    }
}

