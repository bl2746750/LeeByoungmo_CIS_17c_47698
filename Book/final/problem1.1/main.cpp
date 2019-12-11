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
#include <string>
#include <list>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
unsigned int mrkHash(int ,int);
char* filArry(char [],int,bool);
int convert2Num(char [], int );
void displayHash(list<string>*, int);

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
    unsigned int index;
    list<string>* lstArr=new list<string> [LSTSIZE];
    string letters;
    
    //Create the String and Record the hash collissions
    for(int i=0;i<LSTSIZE;i++){
        letters=filArry(array,SIZE,1);
        int num=convert2Num(array,SIZE);
        cout<<num<<", ";
        if(i%11==10) cout << endl;
        count[mrkHash(num,SIZE)%LSTSIZE]++;
        lstArr[mrkHash(num,SIZE)%LSTSIZE].push_back(letters);
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
    
    displayHash(lstArr, LSTSIZE);
    //Exit stage right
    return 0;
}

char* filArry(char a[],int n, bool upLow){
    for(int i=0;i<n;i++){
        int any=rand()%26;
        //int upLow=rand()%2;
        if(upLow)a[i]=any+65;
        else a[i]=any+97;
    }
    a[n]='\0';
    
    return a;
}

int convert2Num(char a[],int n){
    char c;
    int num=0;
    
    for(int i=0;i<n;i++){
        c=a[i];
        if(c>=65&&c<68) num+=0*pow(8,2-i);
        else if(c>=68&&c<71) num+=1*pow(8,2-i);
        else if(c>=71&&c<74) num+=2*pow(8,2-i);
        else if(c>=74&&c<77) num+=3*pow(8,2-i);
        else if(c>=77&&c<80) num+=4*pow(8,2-i);
        else if(c>=80&&c<84) num+=5*pow(8,2-i);
        else if(c>=84&&c<87) num+=6*pow(8,2-i);
        else if(c>=87&&c<91) num+=7*pow(8,2-i);
    }
    return num;
}
unsigned int mrkHash(int num,int n){
    unsigned int digit,sum=0,prod=1;
    unsigned int c;
    for(int i=0;i<n;i++){
        c=num/pow(10,2-i);
        sum+=(sum+c*prod);
        prod*=9;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}

void displayHash(list<string>* tab, int size) { 
  for (int i = 0; i < size; i++) { 
    cout << i; 
    for (auto x : tab[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 