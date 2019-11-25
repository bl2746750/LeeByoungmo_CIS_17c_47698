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
Link *findEnd(Link *);
Link *pushFrt(Link *,int);
Link *pushBck(Link *,int);
bool findVal(Link *,int);
int  cntVal(Link *,int);

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
    list=pushFrt(list,998);
    list=pushBck(list,999);
    list=pushFrt(list,999);
    list=pushBck(list,998);
    prntLnk(list);
    cout<<(findVal(list,999)?"True":"False")<<endl;
    cout<<"999 found "<<cntVal(list,999)<<" times"<<endl;
    //Clean up 
    destroy(list);
    
    //Exit stage right
    return 0;
}

int cntVal(Link *list,int val){
    Link *front=list;
    int cnt=0;
    while(front){
        if(front->data==val)cnt++;
        front=front->ptr;
    }
    return cnt;
}

bool findVal(Link *list,int val){
    Link *front=list;
    while(front){
        if(front->data==val)return true;
        front=front->ptr;
    }
    return false;
}

Link *pushBck(Link *list,int val){
    Link *back=new Link;
    back->data=val;
    back->ptr=0;
    Link *end=findEnd(list);
    end->ptr=back;
    return list;
}

Link *pushFrt(Link *list,int val){
    Link *front=new Link;
    front->data=val;
    front->ptr=list;
    return front;
}

Link *findEnd(Link *list){
    Link *front=list,*back;
    while(front){
        back=front;
        front=front->ptr;
    }
    return back;
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
    cout<<endl;
    while(front){
        cout<<front->data<<endl;
        front=front->ptr;
    }
    cout<<endl;
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