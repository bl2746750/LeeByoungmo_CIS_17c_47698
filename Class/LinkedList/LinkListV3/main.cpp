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
Link *fillLnk(int);
void prntLnk(Link *);
void destroy(Link *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    Link *list;
    
    //Initialize Variables
    list=fillLnk(10);
    
    //Process inputs to outputs/map
    
    //Display the results
    prntLnk(list);

    //Clean up 
    destroy(list);
    
    //Exit stage right
    return 0;
}

void destroy(Link *list){
    Link *front=list;
    while(front){
        Link *temp=front;
        front=front->ptr;
        delete temp;
    }
    list->ptr=0;
}

void prntLnk(Link *list){
    Link *front=list;
    while(front){
        cout<<front->data<<endl;
        front=front->ptr;
    }
}

Link *fillLnk(int n){
    Link *list=new Link[n];
    for(int i=0;i<n-1;i++){
        list[i].data=i+1;
        list[i].ptr=&list[i+1];
    }
    list[n-1].data=n;
    list[n-1].ptr=0;
    return list;
}