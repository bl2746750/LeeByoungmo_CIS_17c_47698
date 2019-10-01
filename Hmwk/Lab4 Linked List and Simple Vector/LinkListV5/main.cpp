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
Link* destroy(Link *);
Link *findEnd(Link *);
Link *pushFrt(Link *,int);
Link *pushBck(Link *,int);
bool findVal(Link *,int);
int  cntVal(Link *,int);
int  lstSize(Link *);
Link *popFrt(Link *,int &);
Link *popBck(Link *,int &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    Link *list;
    
    //Initialize Variables
    list=fillLnk(20);
    prntLnk(list);
    
    //Process inputs to outputs/map
    
    //Display the results
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    int val;
    cout<<"Testing popping a value from the front"<<endl;
    list=popFrt(list,val);
    cout<<"Value from the front = "<<val<<endl;
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    cout<<"Testing popping a value from the Back"<<endl;
    list=popBck(list,val);
    cout<<"Value from the Back = "<<val<<endl;
    prntLnk(list);
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    
    //Clean up 
    list=destroy(list);
    
    prntLnk(list);
    
    cout<<"Size of the list = "<<lstSize(list)<<endl;
    //Exit stage right
    return 0;
}

Link *popBck(Link *list,int &val){
    if(!list)return 0;
    Link *front=list,*back;
    while(front->ptr){
        back=front;
        front=front->ptr;
    }
    val=front->data;
    front=0;
    back->ptr=0;
    return list;
}

Link *popFrt(Link *list,int &val){
    if(!list)return 0;
    val=list->data;
    Link *front=list->ptr;
    delete list;
    return front;
}

int lstSize(Link *list){
    Link *nodePtr, *next;
    if(!list){
//        cout << "!head" << endl;
        return 0;
    }
    else{
        nodePtr=list;

        int cnt=1;
        do{
            cnt++;
            nodePtr=nodePtr->ptr;
        }while(nodePtr->ptr);
//        cout << "size()=" << cnt << endl;
        return cnt;  
    }
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
    if(!list){
        list=front;
        front->ptr=0;
    }
    else{
        Link* secNode=list;
        front->ptr=secNode;
        list=front;
    }
    
    return list;
}

Link *findEnd(Link *list){
    Link *front=list,*back;
    while(front){
        back=front;
        front=front->ptr;
    }
    return back;
}

Link* destroy(Link *list){
    Link *nodePtr=list;
    
    while(nodePtr){
//        cout << "temp->data" << nodePtr->data << endl;
//        cout << "temp->ptr" << nodePtr->ptr << endl;
        nodePtr=list->ptr;
        
        delete list;

        
//        cout << "temp->data" << nodePtr->data << endl;
//        cout << "temp->ptr" << nodePtr->ptr << endl;
       list=nodePtr; 
        
    }
    
//    cout << "size()=" << lstSize(list) << endl;
    return list;
}

void prntLnk(Link *list){
   Link *nodePtr;
    nodePtr=list;
    int cnt=0;
    cout<<endl;
    while(nodePtr){
        cout<<nodePtr->data<<endl;
        nodePtr=nodePtr->ptr;
        cnt++;
    }
    cout<<endl;
    delete nodePtr;  

}

Link *fillLnk(int n){
    Link *front=0;
    
    int cnt=n;
    do{
        front=pushFrt(front,cnt--);
    }while(cnt);
    return front;
}