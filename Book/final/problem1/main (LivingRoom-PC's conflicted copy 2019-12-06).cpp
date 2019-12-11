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
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
unsigned int mrkHash(int ,int);
void filArry(char [],int,bool);
unsigned int convert2Num(char, int );

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int LSTSIZE=512;
    const int SIZE=3;
    char array[SIZE];
    int count[LSTSIZE]={};
    
    //Create the String and Record the hash collissions
    for(int i=0;i<LSTSIZE;i++){
        filArry(array,SIZE,1);
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

void filArry(char a[],int n, bool upLow){
    for(int i=0;i<n;i++){
        int any=rand()%26;
        //int upLow=rand()%2;
        if(upLow)a[i]=any+65;
        else a[i]=any+97;
    }
    a[n]='\0';
}

unsigned int convert2Num(char a[],int n){
    unsigned int num;
    unsigned int converted=0;
    char c;
    
    for(int i=0;i<n;i++){
        c=a[i];
        if(c>=65&&c<68) num=0;
        else if(c>=68&&c<71) num=1;
        else if(c>=71&&c<74) num=2;
        else if(c>=74&&c<77) num=3;
        else if(c>=77&&c<80) num=4;
        else if(c>=80&&c<84) num=5;
        else if(c>=84&&c<87) num=6;
        else if(c>=87&&c<91) num=7;
        num*=pow(8,i);
        converted+=num;
    }
    
   return converted;     
}
unsigned int mrkHash(int converted,int n){
    unsigned int sum=0,prod=1;
    
    for(int i=0;i<n;i++){
        sum+=(sum+c*prod);
        prod*=512;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}