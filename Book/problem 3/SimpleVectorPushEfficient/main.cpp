/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 13th, 2019, 4:31 PM
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <chrono> 
using namespace std;
using namespace std::chrono;


//User Libraries
#include "Object.h"       //2D Objects
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    int totalTime=0;
    int totalSize=0;
    //Test an object
    Object a(3),b(4);
    
    //Test an object by populating the simple vector and print
    SimpleVector<Object> svp(a);
//    cout<<"Simple Vector Object Size = "<<svp.mxSize()<<svp[svp.size()-1];
    //Push an Object and printout the last object
    
    svp.push(b);
    
//    cout<<"Simple Vector Push Size = "<<svp.mxSize()<<svp[svp.size()-1];
    
    //Fill the simple vector with 100 randomly size 2D Array Objects and
    //print the last one
    for(int i=0;i<1000;i++){
        int rSize=rand()%10;
        Object c(rSize);
        auto start = chrono::high_resolution_clock::now();
        svp.push(c);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        totalTime+=duration.count();
        totalSize+=rSize;
    }
    cout << "Total Size: " << totalSize << 
            " Total Time: " << totalTime << " microseconds" << endl;
    cout << "Equal Operator: " << svp.opeq << endl;
    cout << "Greater Than Operator: " << svp.opgt << endl;
    cout << "Increment Operator: " << svp.opinc << endl;
    cout << "Index Operator: " << svp.opindex << endl;
    cout << "Less Than Operator: " << svp.oplt << endl;
    cout << "Minus Operator: " << svp.opmin << endl;
    cout << "Plus Operator: " << svp.opplus << endl;
    cout << "Multiplication: " << svp.opmul << endl;
    cout << "Total Operations: " << svp.opeq+svp.opgt+svp.opinc+svp.opindex+
            svp.oplt+svp.opmin+svp.opplus+svp.opmul << endl;
//    cout<<"Max Size and Size of the Simple Vector = "
//            <<svp.mxSize()<<" "<<svp.size()<<endl;
//    cout<<"The last object in the Vector is "<<endl;
//    cout<<svp[svp.size()-1];
    
    //Create another simple vector by copy constructor
    SimpleVector<Object> csvp(svp);
//    cout<<"Max Size and Size of the Copy Constructed Simple Vector = "
//            <<csvp.mxSize()<<" "<<csvp.size()<<endl;
//    cout<<"The last object in the Vector is "<<endl;
//    cout<<csvp[csvp.size()-1];
 
    //Utilize a simple integer Simple Vector
    int size=50;
    SimpleVector<Object> svi(size);
//    cout<<"Last 2 values of the Simple Vector"<<endl;
//    cout<<"The Max Size and Size = "
//            <<svi.mxSize()<<" "<<svi.size()<<endl
//            <<svi[svi.size()-2]<<svi[svi.size()-1];
    
    //Exit
    return 0;
}