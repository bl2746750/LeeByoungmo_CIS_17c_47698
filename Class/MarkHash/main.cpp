/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 15, 2019, 12:06 PM
 * Purpose:  To show how hash functions are created.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
unsigned int mrkHash(char [],int);
void filArry(char [],int);

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int LSTSIZE=100;
    const int SIZE=20;
    char array[SIZE];
    int count[LSTSIZE]={};
    
    //Create the String and Record the hash collissions
    for(int i=0;i<LSTSIZE;i++){
        filArry(array,SIZE);
        cout<<array<<endl;
        count[mrkHash(array,SIZE-1)%LSTSIZE]++;
    }
    
    //Output the array occupation
    for(int i=0;i<LSTSIZE;i++){
        cout<<count[i]<<" ";
        if(i%10==9)cout<<endl;
    }
    
    //Exit stage right
    return 0;
}

void filArry(char a[],int n){
    for(int i=0;i<n-1;i++){
        int any=rand()%26;
        int upLow=rand()%2;
        if(upLow)a[i]=any+65;
        else a[i]=any+97;
    }
    a[n-1]='\0';
}

unsigned int mrkHash(char a[],int n){
    unsigned int sum=0,prod=1;
    char c;
    for(int i=0;i<n;i++){
        if(a[i]<=91)c=a[i]-65;
        else c=a[i]-71;
        sum+=(sum+c*prod);
        prod*=52;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}