/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 2nd, 2019, 1:19 PM
 * Purpose: Create a Recursive sort
 *          Combine 2 separate arrays into 1
 *          Take that array and merge
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int  *fill(int);
void print(int *,int,int);
int *merge(int *,int,int *,int);
int *merge(int *,int,int);
int *combine(int *,int,int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Allocate the arrays
    int n=10,perLine=10;
    int *a=fill(n);
    int *b=fill(2*n);
    int *ab=combine(a,n,b,2*n);
    //Print the arrays
    print(a,n,perLine);
    print(b,2*n,perLine);
    print(ab,n+2*n,perLine);
    //Merge the arrays then print
    int *c=merge(a,n,b,2*n);
    int *d=merge(ab,n,n+2*n);
    print(c,n+2*n,perLine);
    print(d,n+2*n,perLine);
    //Deallocate data
    delete []a;
    delete []b;
    delete []ab;
    delete []c;
    delete []d;
    //Exit stage right
    return 0;
}

int *combine(int *a,int na,int *b,int nb){
    //Allocate memory
    int *ab=new int[na+nb];
    //First a
    for(int i=0;i<na;i++){
        ab[i]=a[i];
    }
    //Then b
    for(int i=na;i<na+nb;i++){
        ab[i]=b[i-na];
    }
    //Return the combination
    return ab;
}

int *merge(int *hilow,int nlow,int nhigh){
    //Create a merged array
    int *c=new int[nhigh];
    int cntl=0,cnth=nlow;
    //Fill the array
    for(int i=0;i<nhigh;i++){
        if(cntl==nlow){
            c[i]=hilow[cnth++];
        }else if(cnth==nhigh){
            c[i]=hilow[cntl++];
        }else if(hilow[cntl]<hilow[cnth]){
            c[i]=hilow[cntl++];
        }else{
            c[i]=hilow[cnth++];
        }
    }
    //Return the emerged array
    return c;
}

int *merge(int *low,int nlow,int *high,int nhigh){
    //Create a merged array
    int *c=new int[nlow+nhigh];
    int cntl=0,cnth=0;
    //Fill the array
    for(int i=0;i<nlow+nhigh;i++){
        if(cntl==nlow){
            c[i]=high[cnth++];
        }else if(cnth==nhigh){
            c[i]=low[cntl++];
        }else if(low[cntl]<high[cnth]){
            c[i]=low[cntl++];
        }else{
            c[i]=high[cnth++];
        }
    }
    //Return the emerged array
    return c;
}

void print(int *a,int n,int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fill(int n){
    //Allocate memory
    int *a=new int[n];
    for(int i=0;i<n;i++){
        a[i]=i;
    }
    return a;
}