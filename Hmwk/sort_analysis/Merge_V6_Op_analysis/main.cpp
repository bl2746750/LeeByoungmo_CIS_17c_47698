/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 2, 2019, 1:19 PM
 * Purpose: Create a Recursive sort
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Data structure containing an array and a working array
struct Data{
    int size;
    int *sortit;
    int *working;
};

//Global Constants
int opCnt=0;
//Function Prototypes
Data *fill(int);               //Fill the Array
void print(Data *,int);        //Print the array
void merge(Data *,int,int,int);//Merge 2 Arrays algorithm
void mrgSort(Data *,int,int);  //Merge Sort Recursions
void destroy(Data *);          //Deallocate
void mrkSort(Data *);          //Mark sort/my sorting algorithm

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    int n=10000,perLine=5;
    Data *a=fill(n);
    //Print the arrays
    //print(a,perLine);
    //Sort the arrays then print
    //int beg=time(0);
    mrgSort(a,0,a->size);
    //mrkSort(a);
    //int end=time(0);
    cout << "Number of Operations = " << opCnt << endl;
    cout << "For Shell Sort Array Size = " << n << endl;
    //print(a,perLine);
    //Deallocate data
    destroy(a);
    //Exit stage right
    return 0;
}

void mrkSort(Data *a){
    //Utilize mark sort as a comparison
    for(int pos=0;pos<a->size-1;pos++){
        for(int lst=pos+1;lst<a->size;lst++){
            if(a->sortit[pos]>a->sortit[lst]){
                int temp=a->sortit[pos];
                a->sortit[pos]=a->sortit[lst];
                a->sortit[lst]=temp;
            }
        }
    }
}

void destroy(Data *a){
    //Deallocate data elements
    delete []a->sortit;
    delete []a->working;
    delete a;
}

void mrgSort(Data *a,int beg,int end){
    opCnt+=3;
    int center=(beg+end)/2;//Split the task down the middle
    opCnt+=2;
    if((center-beg)>1){
        mrgSort(a,beg,center);//Got to be an array to split
        opCnt++;
    }
    opCnt+=2;
    if((end-center)>1){
        mrgSort(a,center,end);//Got to be an array to split
        opCnt++;
    }
    opCnt++;
    merge(a,beg,center,end);//Merge the sorted arrays into 1 larger sorted array
}

void merge(Data *a,int beg,int nlow,int nhigh){
    opCnt+=4;
    //Create a merged array
    int span=nhigh-beg;    //Span the range to merge
    int cntl=beg,cnth=nlow;//Independent counters to merge the split
    //Fill the array
    opCnt+=3;
    for(int i=0;i<span;i++){
        opCnt+=2;
        if(cntl==nlow){//Low done fill with the higher end of array
            opCnt+=4;
            a->working[i]=a->sortit[cnth++];
        }else if(cnth==nhigh){//High done fill with lower end of array
            opCnt+=4;
            a->working[i]=a->sortit[cntl++];
        }else if(a->sortit[cntl]<a->sortit[cnth]){
            
            a->working[i]=a->sortit[cntl++];//Fill with lower end
        }else{
            opCnt+=4;
            a->working[i]=a->sortit[cnth++];//Fill with higher end
        }
    }
    //Copy back from the working array to the sorted array
    opCnt+=3;
    for(int i=0;i<span;i++){
        opCnt+=5;
        a->sortit[beg+i]=a->working[i];
    }
}

void print(Data *a,int perLine){
    //First print the unsorted array
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->sortit[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Data *fill(int n){
    //Allocate memory
    Data *data=new Data;
    data->size=n;
    data->sortit=new int[n];
    data->working=new int[n];
    for(int i=0;i<n;i++){
        data->sortit[i]=rand();
    }
    return data;
}