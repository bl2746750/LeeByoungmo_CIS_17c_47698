/* 
 * File:   main.cpp
 * Author: Name
 * Date:
 * Purpose:
 */

//System Libraries
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int,int);
bool rndChos(int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int tries=0;
    int tests=10000000;
    int *array=fillAry(tests,.3*tests);
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    cout<<"Biased Coin = "<<pow(.3,5)<<endl;
    for(int i=1;i<=tests;i++){
        tries+=rndChos(array,tests,5);
    }
    cout<<"Simulated Coin = "<<1.0f*tries/tests;

    //Clean up and exit stage right
    delete []array;
    return 0;
}

bool rndChos(int *a,int n,int num){
    int sum=0;
    for(int i=0;i<num;i++){
        sum+=a[rand()%n];
    }
    if(sum==num)return true;
    return false;
}

int *fillAry(int n,int m){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        if(i<m)array[i]=1;
        else array[i]=0;
    }
    return array;
}