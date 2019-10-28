/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 18th, 2019, 4:31 PM
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
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
#include "Object.h"       //2D Object
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
    
    //Output the objects
//    cout<<"Test Object to put in front = ";
//    cout<<a;
//    cout<<"Test Object to put at   end = ";
//    cout<<b;

    //Create a Simple Vector using Linked Lists
    SimpleVector<Object> svp(a);
    
    //Fill the simple vector with 10 randomly size 2D Array Objects and
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
    
    //End the Simple Vector using lists with object b
//    svp.push(b);
//    cout<<"Simple Vector Object size  = "<<svp.size()<<endl;
//    cout<<"Simple Vector Front Object =  "<<svp[0];
//    cout<<"Simple Vector End Object   =  "<<svp[svp.size()-1];
    cout << "Total Size: " << totalSize << 
            " Total Time: " << totalTime << " microseconds" << endl;
    
    cout << "Equal Operator: " << LinkedList<Object>::opeq << endl;
    cout << "Greater Than Operator: " << LinkedList<Object>::opgt << endl;
    cout << "Increment Operator: " << LinkedList<Object>::opinc << endl;
    cout << "Index Operator: " << LinkedList<Object>::opindex << endl;
    cout << "Less Than Operator: " << LinkedList<Object>::oplt << endl;
    cout << "Minus Operator: " << LinkedList<Object>::opmin << endl;
    cout << "Plus Operator: " << LinkedList<Object>::opplus << endl;
    cout << "Multiplication: " << LinkedList<Object>::opmul << endl;
    cout << "Not Equal: " << LinkedList<Object>::opneq << endl;
    cout << "Total Operations: " << LinkedList<Object>::opeq+LinkedList<Object>::opgt
            +LinkedList<Object>::opinc+LinkedList<Object>::opindex+
            LinkedList<Object>::oplt+LinkedList<Object>::opmin+
            LinkedList<Object>::opplus+LinkedList<Object>::opmul+
            LinkedList<Object>::opneq << endl;
    //Exit*/
    return 0;
}