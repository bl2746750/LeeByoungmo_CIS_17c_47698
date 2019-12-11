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
unsigned int mrkHash(char [] ,int);
void filArry(char [],int,bool);
void convert2Num(char [], int );

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int LSTSIZE=512;
    const int SIZE=3;
    char array[SIZE];
    int count[LSTSIZE]={};
    int confl[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    //Create the String and Record the hash collissions
    for(int i=0;i<LSTSIZE;i++){
        filArry(array,SIZE,1);
        convert2Num(array,SIZE);
        cout<<array<<", ";
        if(i%11==10) cout << endl;
        count[mrkHash(array,SIZE)%LSTSIZE]++;
    }
    
    cout << endl;
    //Output the array occupation
    
    for(int i=0;i<LSTSIZE;i++){
        cout<<count[i]<<" ";
        if(count[i]==0) confl[0]++;
        else if(count[i]==1) confl[1]++;
        else if(count[i]==2) confl[2]++;
        else if(count[i]==3) confl[3]++;
        else if(count[i]==4) confl[4]++;
        else if(count[i]==5) confl[5]++;
        else if(count[i]==6) confl[6]++;
        else if(count[i]==7) confl[7]++;
        else if(count[i]==8) confl[8]++;
        else if(count[i]==9) confl[9]++;
        else if(count[i]==10) confl[10]++;
        else if(count[i]==11) confl[11]++;
        else if(count[i]==12) confl[12]++;
        else if(count[i]==13) confl[13]++;
        if(i%10==9)cout<<endl;
    }
    cout << endl;
    
    for(int i=0;i<14;i++){
        cout << "#of conflict=" << i <<" : " << confl[i] << ", " << confl[i]*1.0/512*100 << " %"<< endl;
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

void convert2Num(char a[],int n){
    char c;
    
    for(int i=0;i<n;i++){
        c=a[i];
        if(c>=65&&c<68) a[i]=48;
        else if(c>=68&&c<71) a[i]=49;
        else if(c>=71&&c<74) a[i]=50;
        else if(c>=74&&c<77) a[i]=51;
        else if(c>=77&&c<80) a[i]=52;
        else if(c>=80&&c<84) a[i]=53;
        else if(c>=84&&c<87) a[i]=54;
        else if(c>=87&&c<91) a[i]=55;
    }
    
}
unsigned int mrkHash(char a[],int n){
    unsigned int sum=0,prod=1;
    char c;
    for(int i=0;i<n;i++){
        c=a[i]-48;
        sum+=(sum+c*prod);
        prod*=9;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}