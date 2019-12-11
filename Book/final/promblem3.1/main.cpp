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
int compareWins(queue<customer> *, int n);
int main(){
    queue<customer> qLine;
    queue<customer> qWin[5];
    
    int SIZE=100;
    int WIN_NUM=5;
    int numWin=-1;
    float totalWait=0;
    
    customer cust[SIZE];
    customer winClosed[2];
    
//    for(int i=0;i<SIZE;i++){
//        cust[i].arrTime=-1;
//        cust[i].servTime=-1;
//        cust[i].waitTime=-1;
//        cust[i].totalTime=0;
//    }
    for(int i=0;i<2;i++){
        winClosed[i].totalTime=60*60*10;
    }
    
    
    qWin[3].push(winClosed[0]);
    qWin[4].push(winClosed[1]);
    
    for(int i=0;i<SIZE;i++){
        cust[i].arrTime=15*(i+1);
        qLine.push(cust[i]);
        customer *frontL=&qLine.front();
        numWin=checkEmptyWin(qWin,WIN_NUM);
        //cout << "numWin: " << numWin << endl;
        //cout << "nth: " << i << endl;
        if(numWin!=-1) {
            qLine.pop();
            qWin[numWin].push(*frontL);
            frontL->waitTime=0;
            frontL->servTime=checkServTime(numWin);
            frontL->totalTime=frontL->arrTime+frontL->servTime+frontL->waitTime;
            cout << "window #: " << numWin << endl;
            cout << "nth: " << i << endl;
            cout << "custWin waitTime: " << frontL->waitTime << endl;
            cout << "custWin serviceTime " << frontL->servTime << endl;
            cout << "custWin arrival Time " << frontL->arrTime << endl;
            cout << "custWin Total Time: " << frontL->totalTime << endl;
        }
        else {
            numWin=compareWins(qWin,WIN_NUM);
            cout << "numWin:" << numWin << endl;
            customer* backL=&qLine.back();
            customer* frontW=&qWin[numWin].front();
            if(backL->arrTime>frontW->totalTime){
                qWin[numWin].pop();
                qLine.pop();
                qWin[numWin].push(*frontL);
                frontL->waitTime=frontW->totalTime-frontL->arrTime;
                frontL->servTime=checkServTime(numWin);
                frontL->totalTime=frontL->arrTime+frontL->servTime+frontL->waitTime;
                cout << "window #: " << numWin << endl;
                cout << "nth: " << i << endl;
                cout << "custWin waitTime: " << frontL->waitTime << endl;
                cout << "custWin serviceTime " << frontL->servTime << endl;
                cout << "custWin arrival Time " << frontL->arrTime << endl;
                cout << "custWin Total Time: " << frontL->totalTime << endl;
            }
            else{cout << "error" << endl;}
        }
//        cout << cust[i].waitTime << endl;
//        cout << cust[i].servTime << endl;
//        cout << cust[i].arrTime << endl;
//        cout << cust[i].totalTime << endl;
        //cout << qLine.size() << endl;
        //totalWait+=cust[i].waitTime;
    }
    
    //cout << totalWait*1.0/SIZE<< endl;
    
    
    //Exit stage right!
    return 0;
}


int compareWins(queue<customer> *q,int n){
    float min;
    int fastWin=0;
    cout << "size of queue: " << q[0].size() << endl;
    customer *custWin0=&q[1].front();
    cout << "cust0: " << custWin0->totalTime << endl;
//    customer *custWin[n]={nullptr,nullptr,nullptr,nullptr,nullptr};
//    
//    for(int i=0;i<n;i++){
//        if(!q[i].empty()) {
//            custWin[i]=&q[i].front();
//            cout << "custWin[" << i << "] = " << custWin[i]->totalTime << endl; 
//        }
//    }
//    min=custWin[fastWin]->totalTime;
//    
//    for(int i=1;i<n;i++){
//        if(min>custWin[i]->totalTime){
//            min=custWin[i]->totalTime;
//            fastWin=i;
//            cout <<"min: " <<   min << endl;
//        }
//        
//    }
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