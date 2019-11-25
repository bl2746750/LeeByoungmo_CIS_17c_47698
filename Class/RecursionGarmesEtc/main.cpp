/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   Oct 31st, 2019
 * Purpose:Fun with Recursions
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float fv(float,float,int);
void hanoi(int,int,int,int);
int maxRec(int *,int,int);
int maxLin(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int a1[]={5,4,3,2,1,6,1,2,3,4,5};
    int a2[]={5,4,3,2,1};
    int a3[]={1,2,3};
    
    //Initialize Variables
    
    //Process inputs to outputs/map and Display
    cout<<"Finance / Savings function illustrating the Rule 72"<<endl;
    float pv=100,i=0.03f;
    int n=24;
    cout<<"Fv("<<pv<<","<<i<<","<<n<<")=$"<<fv(pv,i,n)<<endl;
    i=0.06f;n=12;
    cout<<"Fv("<<pv<<","<<i<<","<<n<<")=$"<<fv(pv,i,n)<<endl;
    i=0.08f;n=9;
    cout<<"Fv("<<pv<<","<<i<<","<<n<<")=$"<<fv(pv,i,n)<<endl;
    i=0.09f;n=8;
    cout<<"Fv("<<pv<<","<<i<<","<<n<<")=$"<<fv(pv,i,n)<<endl;
    i=0.12f;n=6;
    cout<<"Fv("<<pv<<","<<i<<","<<n<<")=$"<<fv(pv,i,n)<<endl;
    i=0.24f;n=3;
    cout<<"Fv("<<pv<<","<<i<<","<<n<<")=$"<<fv(pv,i,n)<<endl;
    
    //Output the results of the Hanoi Game
    hanoi(3,1,2,3);
    
    //Output the maximum for each array
    cout<<"Max for each array"<<endl;
    cout<<"Array max 1 = "<<maxRec(a1,0,sizeof(a1)/sizeof(int))<<endl;
    cout<<"Array max 1 = "<<maxLin(a1,sizeof(a1)/sizeof(int))<<endl;
    cout<<"Array max 2 = "<<maxRec(a2,0,sizeof(a2)/sizeof(int))<<endl;
    cout<<"Array max 2 = "<<maxLin(a2,sizeof(a2)/sizeof(int))<<endl;
    cout<<"Array max 3 = "<<maxRec(a3,0,sizeof(a3)/sizeof(int))<<endl;
    cout<<"Array max 3 = "<<maxLin(a3,sizeof(a3)/sizeof(int))<<endl;
    
    //Clean up and exit stage right
    return 0;
}

int maxLin(int *a,int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(max<a[i])max=a[i];
    }
    return max;
}

int maxRec(int *a,int beg,int end){
    if(end-beg<=1)return a[beg];
    int half=(end+beg)/2;
    int m1=maxRec(a,beg,half);
    int m2=maxRec(a,half,end);
    return (m1<m2?m2:m1);
}

void hanoi(int nDisks,int src,int spare,int dest ){
    if(nDisks>1)hanoi(nDisks-1,src,dest,spare);
    cout<<"Move -> "<<src<<" to -> "<<dest<<endl;
    if(nDisks>1)hanoi(nDisks-1,spare,src,dest);
}

float fv(float pv,float i,int n){
    //Base Case
    if(n<=0)return pv;
    //Recursion
    return fv(pv,i,n-1)*(1+i);
}