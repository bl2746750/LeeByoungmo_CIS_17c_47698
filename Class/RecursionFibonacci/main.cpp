/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 22nd, 2019
 * Purpose:Explore Fibonacci Implementation
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float fiboRpl(int);
float fiboAry(int);
float fiboRec(int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    int nLoop=40;
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    cout<<"Compare Fibonacci"<<endl;
    cout<<" N   Recursive     Swap/Replace         Array           Phi"<<endl;
            
    for(int i=0;i<=nLoop;i++){
        cout<<setw(2)<<i;
        cout<<setw(12)<<fiboRec(i);
        cout<<setw(17)<<fiboRpl(i);
        cout<<setw(14)<<fiboAry(i);
        if(i<2)cout<<endl;
        else cout<<setw(14)<<fiboRpl(i)/fiboRpl(i-1)<<endl;
    }
    
    //Display the results

    //Clean up and exit stage right
    return 0;
}

float fiboAry(int n){
    if(n<=0)return 0;
    float *array=new float[n+1];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<=n;i++){
        array[i]=array[i-1]+array[i-2];
    }
    float temp=array[n];
    delete []array;
    return temp;
}

float fiboRpl(int n){
    float fn1,fn2,fn;
    fn2=0;fn1=1;
    if(n<=0)return fn2;
    if(n==1)return fn1;
    n-=2;
    do{
        fn=fn1+fn2;
        fn2=fn1;
        fn1=fn;
    }while(n--);
    return fn;
}

float fiboRec(int n){
    //Base Conditions
    if(n<=0)return 0;
    if(n==1)return 1;
    return fiboRec(n-1)+fiboRec(n-2);
}