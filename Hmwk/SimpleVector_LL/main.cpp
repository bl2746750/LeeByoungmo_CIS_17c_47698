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
void fillVec(SimpleVector<unsigned int> &);
void prntVec(SimpleVector<unsigned int> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    unsigned int size=2;
    SimpleVector<unsigned int> sv(size);
//    sv.prntLst();
//    //Fill the Vector
//    fillVec(sv);
//    //Print the Vector
//    prntVec(sv,10);
//    cout << "size()="<<sv.size() << endl;
    //Copy the Vector
//    SimpleVector<unsigned int> copysv(sv);
//    //Print the Vector
//    prntVec(copysv,10);
//    
//    //Destroy the Vector 
//    sv.dstryLst();
//    //print the Vector
//    sv.prntLst(); //nothing printed out
//    copysv.prntLst(); //but, copied printed out normally
//    
//    for(int i=0;i<5;i++){
//        copysv.pop_back();   //pop_back() five times
//        copysv.pop_front();  //pop_front() five times
//    }
//    
//    prntVec(copysv,10);      //print the Vector
//    cout << "size()="<<copysv.size() << endl;
//    
//    copysv.push_back(10);
//    copysv.push_back(10);
//    copysv.push_back(10);
//    cout << "size()="<<copysv.size() << endl;
//    for(int i=0;i<10;i++){
//        
//        copysv.push_front(i);//pop_back() 0~9
//        copysv.push_back(i); //pop_back() 0~9 
//    }
//    cout << "size()="<<copysv.size() << endl;
//    prntVec(copysv,10);      //print the Vector
//    copysv.prntLst();
//////    cout << "size()="<<copysv.size() << endl;
    return 0;
}

void prntVec(SimpleVector<unsigned int> &sv,int perLine){
    cout<<endl;
    for(int i=0;i<sv.size();i++){
        cout<<sv[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillVec(SimpleVector<unsigned int> &sv){
    for(int i=0;i<sv.size();i++){
        sv[i]=rand()%26+65;
    }
//    for(int i=0;i<sv.size();i++){
//        cout << sv.getElementAt(i) << endl;
//    }
}

