/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Date:   October 8th, 2019 10:04am
 * Purpose:Doubly Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries
#include "Link.h"

//Global Constants

//Function Prototypes
Link *fillLnk(int);
void prntLnk(Link *);
Link* destroy(Link *);
//Link *ascInput(Link *,int);
//Link* search(Link*, int);

//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here

    //Declare Variables
    Link *list;

    //Initialize Variables
    cout << "list by the order of fill-in: ";
    list = fillLnk(10);

    //Process inputs to outputs/map
    
    //Display the results
    cout << "\nDoubly Sorted Linked List   : ";prntLnk(list);

    
    
    //prioritized Lst1;
//    list=search(list,8);
//    cout << "prioritized list1           : ";
//    prntLnk(list);
//    
//    //prioritized Lst2;
//    list=search(list,10);
//    cout << "prioritized list2           : ";
//    prntLnk(list);
//    //Exit stage right
    
    //Clean up 
    list=destroy(list);
    prntLnk(list);

    return 0;
}

//Link* search(Link* list, int num){
//    Link* nodePtr=list;
//    Link* prevNode,*nextNode,*front;
//    front=list;
//    //int pos=0;
//    while(nodePtr->data!=num){
//        nodePtr=nodePtr->next;
//    //    pos++;
//    }
//    //cout << endl << "Search 8: position = " << search(list,8) << endl;
//    
//    if(front!=nodePtr){
//        prevNode=nodePtr->prev;
//        if(nodePtr->next)
//            {
//            nextNode=nodePtr->next;
//            prevNode->next=nextNode;
//            nextNode->prev=prevNode;
//        }
//        else{
//            prevNode->next=0;
//        }
//        
//        nodePtr->next=front;
//        nodePtr->prev=0;    
//    }
//    
//    front=nodePtr;

//    }
    
//    return front;
//}
Link* destroy(Link *list) {
    Link *front = list;
    Link *temp;
    
    while (front) {
        temp = front;
        
        front = front->next;
        delete temp;
        //prntLnk(front);
    }
    front->next=0;
    list=front;
    
    return list; 
}

void prntLnk(Link *list) {
    Link *front = list;
    //front=front->next;
    while (front) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}


//Link *fillLnk(int n) {
//    //srand(time(0));
////    int* val=new int [n];
//    Link* head = 0;
//    int cnt=n;
//    if (n) {
////        for(int i=0;i<n;i++){
////            val[i]=rand()%89+10;
////            cout << val[i] << " ";
////        }
////        cout << endl;
//        for(int i=0;i<n;i++){
//            cout << cnt << " ";
//            head=ascInput(head,cnt--);
//        }
//    }
//    return head;
//}
Link *fillLnk(int n) {
    srand(time(0));
    int a;
    Link* newNode = new Link [n];
    Link* head = 0;

    if (n) {
        head = &newNode[0];
        newNode[0].prev = 0;
        newNode[0].next = &newNode[1];


        for (int i = 1; i < n - 1; i++) {
            newNode[i].next = &newNode[i + 1];
            newNode[i].prev = &newNode[i - 1];
        }
        newNode[n - 1].prev = &newNode[n];
        newNode[n - 1].next = 0;

        for (int i = 0; i < n; i++) {
            a=rand()%89+10;
            newNode[i].data = a;
            cout << a << " ";
        }
    }
    return head;
}

//Link *ascInput(Link* list,int val) {
////    srand(time(0));
//    
//    Link* nodePtr=list, *cur=0;
//    Link* newPtr=new Link;
//    
//    newPtr->data=val;
//    newPtr->next=0;
//    newPtr->prev=0;
//    //cout << newPtr->data << endl;
//    
//    if (!nodePtr) {
//        list=newPtr;
//    }
//        
//    else{
//        if(newPtr->data<nodePtr->data){
//            newPtr->next=nodePtr;
//            nodePtr->prev=newPtr;
//            list=newPtr;
//        }
//        else{
//            cur=nodePtr;
//            while(newPtr->data>=nodePtr->data&&nodePtr->next){
//                nodePtr=nodePtr->next;
//                cur=nodePtr->prev;
//            }
//            if(newPtr->data<=nodePtr->data){
//                newPtr->next=nodePtr;
//                newPtr->prev=cur;
//                cur->next=newPtr;
//                nodePtr->prev=newPtr;
//            }
//            else{
//                nodePtr->next=newPtr;
//                newPtr->prev=nodePtr;
//            }
//            while(cur->prev){
//                cur=cur->prev;
//            }
//            list=cur;
//        }
//               
//        
//    }
//    
//    //cout << endl;
//    //prntLnk(list);
//    
//    return list;
//}