/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on October 15th, 2019, 10:05 AM
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 
using namespace std;
using namespace std::chrono;


//User Libraries Here

//Global Constants Only, No Global Variables
long int opeq=0;
long int oplt=0;
long int opinc=0;
long int opindex=0;
long int opplus=0;
long int opmin=0;
long int opgt=0;
long int opeq1=0;
long int oplt1=0;
long int opinc1=0;
long int opindex1=0;
long int opplus1=0;
long int opmin1=0;
long int opgt1=0;
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void bublSrt(int [],int);
void selSort(int [],int);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=25600;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=200;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in the array
//    prntAry(array,SIZE,perLine);
//    prntAry(brray,SIZE,perLine);
    
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    auto start1 = chrono::high_resolution_clock::now();
    bublSrt(array,SIZE);
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    
    auto start2 = chrono::high_resolution_clock::now();
    selSort(brray,SIZE);
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    
    cout << "Size=" << SIZE << endl;
    cout << "Time(Buble Sort) = " << duration1.count() << endl;
    cout << "Equal Operator: " << opeq1 << endl;
    cout << "Greater Than Operator: " << opgt1 << endl;
    cout << "Increment Operator: " << opinc1 << endl;
    cout << "Index Operator: " << opindex1 << endl;
    cout << "Less Than Operator: " << oplt1 << endl;
    cout << "Minus Operator: " << opmin1 << endl;
    cout << "Plus Operator: " << opplus1 << endl;
    cout << "Total Operations: " << opeq1+opgt1+opinc1+opindex1+
            oplt1+opmin1+opplus1 << endl;
    cout << "Time(Selection Sort) = " << duration2.count() << endl;    
    cout << "Equal Operator: " << opeq << endl;
    cout << "Greater Than Operator: " << opgt << endl;
    cout << "Increment Operator: " << opinc << endl;
    cout << "Index Operator: " << opindex << endl;
    cout << "Less Than Operator: " << oplt << endl;
    cout << "Minus Operator: " << opmin << endl;
    cout << "Plus Operator: " << opplus << endl;
    cout << "Total Operations: " << opeq+opgt+opinc+opindex+
            oplt+opmin+opplus << endl;
    //Test the linear search by randomly choosing a value and
    //determine if found;
//    int value=rand()%(highRng-lowRng+1)+lowRng;
//    cout<<"Using the Linear Search"<<endl;
//    cout<<"The value "<<value<<" was found at position "
//            <<linSrch(array,SIZE,value)<<endl;
//    cout<<"Using the Binary Search"<<endl;
//    cout<<"The value "<<value<<" was found at position "
//            <<binSrch(brray,SIZE,value)<<endl;
    
    
    //Print the values in the array
//    prntAry(array,SIZE,perLine);
//    prntAry(brray,SIZE,perLine);

    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    opeq++;
    for(int pos=0;pos<n-1;pos++){
        oplt++;opmin++;opinc++;opeq+=3;opindex++;opplus;
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            oplt++;opinc+=2;
            if(a[i]<min){
                opeq+=2;opindex++;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        opeq+=2;opindex+=3;
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        opeq1+=2;
        swap=false;
        //Check the list and Swap when necessary
        for(int i=0;i<n-1;i++){
            oplt1++;opmin1++;opinc1++;opgt1++;opindex1+=2;opplus1++;
            if(a[i]>a[i+1]){
                opeq1+=4;opindex1+=4;opplus1+=2;
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
        opeq1++;
    }while(swap);
}

int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle])return middle;
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

int  linSrch(int a[],int n, int val){
    for(int indx=0;indx<n;indx++){
        if(val==a[indx])return indx;
    }
    return -1;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}