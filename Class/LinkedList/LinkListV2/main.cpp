/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   Sept 24th, 2019
 * Purpose:Exploration of a Linked List
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Link.h"

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    Link *lnk1,*lnk2,*lnk3;
    
    //Initialize Variables
    lnk1=new Link;
    lnk2=new Link;
    lnk3=new Link;
    
    //Process inputs to outputs/map
    lnk1->data=1;
    lnk2->data=2;
    lnk3->data=3;
    lnk1->ptr=lnk2;
    lnk2->ptr=lnk3;
    lnk3->ptr=0;
    
    //Display the results
    Link *front=lnk1;
    while(front){
        cout<<front->data<<endl;
        front=front->ptr;
    }

    //Clean up 
    delete []lnk1;
    delete []lnk2;
    delete []lnk3;
    
    //Exit stage right
    return 0;
}