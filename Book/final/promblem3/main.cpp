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
int checkAvailWin(queue<customer> [],int);
float checkServTime(int);
int compareWins(queue<customer> q[], int n);

int main(){
    queue<customer> qLine;
    queue<customer> qWin[5];
    
    int SIZE=100;
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
        numWin=checkAvailWin(qWin,5);
        if(qWin[numWin].empty()) {
            customer &front=qLine.front();
            front.waitTime=0;
            //cout << front.waitTime << endl;
            front.servTime=checkServTime(numWin);
            //cout << front.servTime << endl;
            front.totalTime=cust[i].arrTime+cust[i].servTime+cust[i].waitTime;
            qLine.pop();
            qWin[numWin].push(cust[i]);
        }
        else {
            cout << numWin << endl;
            customer &timeChecker=qLine.back();
            customer &front=qLine.front();
            customer custWin=qWin[numWin].front();
            if(timeChecker.arrTime>custWin.totalTime){
                cout << custWin.waitTime << endl;
                cout << custWin.servTime << endl;
                cout << custWin.arrTime << endl;
                cout << custWin.totalTime << endl;
                front.waitTime=custWin.totalTime-front.arrTime;
                cout << front.waitTime << endl;
                front.servTime=checkServTime(numWin);
                cout << front.servTime << endl;
                front.totalTime=front.arrTime+front.servTime+front.waitTime;
                qWin[numWin].pop();
                qLine.pop();
                qWin[numWin].push(cust[i]);
            }
        }
//        cout << cust[i].waitTime << endl;
//        cout << cust[i].servTime << endl;
//        cout << cust[i].arrTime << endl;
//        cout << cust[i].totalTime << endl;
        //cout << qLine.size() << endl;
        totalWait+=cust[i].waitTime;
    }
    
    //cout << totalWait*1.0/SIZE<< endl;
    
    
    //Exit stage right!
    return 0;
}

int compareWins(queue<customer> q[],int n){
    float min;
    int fastWin=0;
    customer* custWin=new customer[n];
    for(int i=0;i<n;i++){
        custWin[i]=q[i].front();
        cout << "custWin[" << i << "]: "  << custWin[i].totalTime << endl;
    }
    min=custWin[fastWin].totalTime;
    for(int i=1;i<n;i++){
        if(min>custWin[i].totalTime){
            min=custWin[i].totalTime;
            fastWin=i;
            cout << "min: " << min << endl;
        }
    }
    delete[] custWin;
    return fastWin;
    
}
int checkAvailWin(queue<customer> q[],int n){
    int cnt=0;
    int found=-1;
    int fastWin;
    
    while(!q[cnt].empty()&&cnt>=n){
        if(q[cnt].empty()) found=cnt;
        cnt++;
    }
    
    if(found==-1){
        found=compareWins(q,n);
    }
    //cout << found << endl;
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
        default:serTime=120;break;
    }
    return serTime;
}