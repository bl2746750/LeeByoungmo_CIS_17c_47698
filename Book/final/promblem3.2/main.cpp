/* 
 * Author: Student Byoung Mo Lee
 * Created on December 7, 2019, 3:00 AM
 * Purpose: Final Problem3
 */


#include <iostream>
#include <queue>
using namespace std;
 
#include "customer.h"


/* Driver program to test above functions*/
int checkEmptyWin(queue<customer> *,int);
float checkServTime(int);
int compareWins(customer**, int);
int main(){
    queue<customer> qLine;
    queue<customer> qWin[5];
    
    int SIZE=300;
    int WIN_NUM=5;
    int numWin=-1;
    float totalWait=0;
    int line=0;
    
    customer cust[SIZE];
    customer winClosed3,winClosed4;
    customer* clerk[5]={nullptr,nullptr,nullptr,nullptr,nullptr};
    customer* custFront=&qLine.front();
    customer* custBack=&qLine.back();

    winClosed3.totalTime=10e8;
    winClosed4.totalTime=10e8;
    
    qWin[3].push(winClosed3);
    clerk[3]=&qWin[3].front();
    qWin[4].push(winClosed4);
    clerk[4]=&qWin[4].front();
    
    for(int i=0;i<SIZE;i++){
        cust[i].arrTime=15*(i+1);
        qLine.push(cust[i]);
        custBack=&qLine.back();
        custFront=&qLine.front();
        //cout << custFront->arrTime << endl;
        if(qLine.size()>=5&&clerk[3]->totalTime==10e8)  {
            qWin[3].pop();
            clerk[3]=&qWin[3].front();
            
            
        }
        else if(qLine.size()>=10&&clerk[4]->totalTime==10e8){
                qWin[4].pop();
                clerk[4]=&qWin[4].front();
        }
        
        numWin=checkEmptyWin(qWin,WIN_NUM);
        //cout << "numWin: " << numWin << endl;
        //cout << "nth: " << i << endl;
        if(numWin!=-1) {
            custFront->waitTime=0;
            custFront->servTime=checkServTime(numWin);
            custFront->totalTime=custFront->arrTime+custFront->servTime+custFront->waitTime;
            cout << "window #: " << numWin << endl;
            cout << "nth: " << i << endl;
            cout << "custWin waitTime: " << custFront->waitTime << endl;
            cout << "custWin serviceTime " << custFront->servTime << endl;
            cout << "custWin arrival Time " << custFront->arrTime << endl;
            cout << "custWin Total Time: " << custFront->totalTime << endl;
            
            qLine.pop();
            qWin[numWin].push(*custFront);
            clerk[numWin]=&qWin[numWin].front();
            custFront=&qLine.front();
            custBack=&qLine.back();
        }
        else {
            
            numWin=compareWins(clerk,WIN_NUM);
            custBack=&qLine.back();
            clerk[numWin]=&qWin[numWin].front();
            if(custBack->arrTime>clerk[numWin]->totalTime){
                custFront->waitTime=clerk[numWin]->totalTime-custFront->arrTime;
                if(custFront->waitTime<0) custFront->waitTime=0;
                custFront->servTime=checkServTime(numWin);
                custFront->totalTime=custFront->arrTime+custFront->servTime+custFront->waitTime;
                cout << "window #: " << numWin << endl;
                cout << "nth: " << i << endl;
                cout << "custWin waitTime: " << custFront->waitTime << endl;
                cout << "custWin serviceTime " << custFront->servTime << endl;
                cout << "custWin arrival Time " << custFront->arrTime << endl;
                cout << "custWin Total Time: " << custFront->totalTime << endl;
                
                qWin[numWin].pop();
                qLine.pop();
                qWin[numWin].push(*custFront);
                clerk[numWin]=&qWin[numWin].front();
                custFront=&qLine.front();
                custBack=&qLine.back();
            }
            
        }
        cout << "customers waiting in the line: "  << qLine.size() << endl;
        //if(qLine.size()>=5)  qWin[3].pop();
        //totalWait+=cust[i].waitTime;
    }
    
    //cout << totalWait*1.0/SIZE<< endl;
    
    
    //Exit stage right!
    return 0;
}


int compareWins(customer** clerks,int n){
    float min;
    int fastWin=0;
    
    
    min=clerks[fastWin]->totalTime;
    
    for(int i=1;i<n;i++){
        if(min>clerks[i]->totalTime){
            min=clerks[i]->totalTime;
            fastWin=i;
            cout <<"min: " <<   min << endl;
        }
        
    }
//    delete []custWin;
    return fastWin;
    
}
int checkEmptyWin(queue<customer> *q,int n){
    int cnt=0;
    int found=-1;
    
    do{
        if(q[cnt].empty()) found=cnt;
        cnt++;
    }while(found==-1&&cnt<n);
    
    
    return found;
}

float checkServTime(int winNum){
    float serTime=-1;
    switch(winNum){
        case 0:serTime=60;break;
        case 1:serTime=120;break;
        case 2:serTime=80;break;
        case 3:serTime=60;break;
        case 4:serTime=60;break;
        default:break;
    }
    return serTime;
}