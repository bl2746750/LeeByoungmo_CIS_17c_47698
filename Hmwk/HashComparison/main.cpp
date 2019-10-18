/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Created on October 17, 2019, 16:31 PM
 * Purpose:  Hash Comparison
 */

//System Libraries
#include <chrono> 
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;
using namespace std::chrono; 

//User Libraries

//Global Constants

//Function prototypes
unsigned int mrkHash(string,int);
string filArry(int);
string* makeAry(int, int);
list<int>* makeHashTab(string [],int, int);
int hashFind(char [], int, list<int>*);
void displayHash(list<int>*, int);
string* makeSrchLST(string [],int, int, int);
int hashFind(string,int, list<int>*,int,string*);
int linearSearch(const string[],int,string);
int binarySearch(const string[],int,string);


//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    const int LSTSIZE=100;
    const int SIZE=20;
    const int SrchSize=10;
    string *strList=makeAry(SIZE,LSTSIZE);
    list<int> *HashTab=makeHashTab(strList,LSTSIZE, SIZE);
    string *srchLst=makeSrchLST(strList,LSTSIZE, SrchSize, SIZE);
    
    auto start = chrono::high_resolution_clock::now();
    for(int i=0;i<SrchSize;i++){
        hashFind(srchLst[i],SIZE,HashTab,LSTSIZE,strList);
        //linearSearch(strList,LSTSIZE,srchLst[i]);
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
//    sort(strList,strList+LSTSIZE);
//    
//    auto start = chrono::high_resolution_clock::now();
//    for(int i=0;i<SrchSize;i++){
//        //hashFind(srchLst[i],SIZE,HashTab,LSTSIZE,strList);
//        binarySearch(strList,LSTSIZE,srchLst[i]);
//    }
//    auto stop = chrono::high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
    //Output the array occupation
    cout <<  duration.count() << " microseconds" << endl; 
         
//    displayHash(HashTab, LSTSIZE);
    //Exit stage right
    delete [] strList;
    delete [] srchLst;
    delete [] HashTab;
    
    return 0;
}
int hashFind(string a,int size, list<int>* ht, int lstSize,string lst[]){
    int index=mrkHash(a,size)%lstSize;
    int found=0;
    if(ht[index].empty()) {return -1;}
    else{
        for (auto x : ht[index]){ 
            if(a==lst[x]) {
                found=1;
                return x;
            }
        }
    if(!found) return -1;
    }
    
    
}
    

string* makeSrchLST(string Lst[],int LstSize, int srchSize, int strSize){
    string* srchLst=new string [srchSize];
    for(int i=0;i<srchSize/2;i++){
        srchLst[i]=filArry(strSize);
//        cout << srchLst[i] << endl;
    }
    for(int i=srchSize/2;i<srchSize;i++){
        int any=rand()%(LstSize-1);
        srchLst[i]=Lst[any];
//        cout << srchLst[i] << endl;
    }
//    for(int i=0;i<srchSize;i++){
//        cout << srchLst[i] << endl;
//    }
    return srchLst;
}

string* makeAry(int aSize, int sArySize){
    string *sAry=new string [sArySize];
    for(int i=0;i<sArySize;i++){
        sAry[i]=filArry(aSize);
    }
    
    return sAry;
}

list<int>* makeHashTab(string sAry[],int sArySize, int chSize){
    list<int>* tab=new list<int> [sArySize];
    int index;
    for(int i=0;i<sArySize;i++){
        index=mrkHash(sAry[i],chSize)%sArySize;
        tab[index].push_back(i);
    }
    return tab;
}

string filArry(int n){
    string a="";
    for(int i=0;i<n;i++){
        int any=rand()%26;
        int upLow=rand()%2;
        if(upLow)a+=any+65;
        else a+=any+97;
    }
//    cout << a << endl;
//    a[n-1]='\0';
    return a;
}

unsigned int mrkHash(string a,int n){
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

//int firstFindHsh(int posTab, int idx){
//    if(tab[idx]!=0) {return tab[idx];}
//    else {return -1;}
//}

void displayHash(list<int>* tab, int size) { 
  for (int i = 0; i < size; i++) { 
    cout << i; 
    for (auto x : tab[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 

int linearSearch(const string arr[],int size, string value){
    int index=0;
    int position=-1;
    bool found=false;
    
    while(index<size&&!found){
        if(arr[index]==value){
            found=true;
            position=index;
        }
        index++;
    }
    return position;
}

int binarySearch(const string arr[],int size,string value){
    int first=0,
            last=size-1,
            middle,
            position=-1;
    bool found=false;
    
    while(!found && first<=last){
        middle=(first+last)/2;
        if(arr[middle]==value){
            found=true;
            position=middle;
        }
        else if(arr[middle]>value) last=middle-1;
        else first=middle+1;
    }
    return position;
}