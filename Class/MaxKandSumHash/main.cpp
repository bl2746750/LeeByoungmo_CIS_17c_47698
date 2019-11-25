/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 9th,2019
 * Purpose:Correspond Max K and Sum Simulated
 * with Theory Hashing Theory
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fill(int);
void prnt(int *,int,int);
int  sum(int *,int);
int  max(int *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int n=500000000;
    int *sumAry;
    int *kMaxAry;
    
    //Initialize Variables
    sumAry=fill(n);
    kMaxAry=fill(n);
    
    //Process inputs to outputs/map
    for(int i=0;i<n;i++){
        int hash=rand()%n;
        sumAry[hash]=(sumAry[hash]?1:1);
        kMaxAry[hash]++;
    }
    float theory=n*(1-exp(-1));
    
    //Display the results
    /*cout<<"Sum Array"<<endl;
    prnt(sumAry,n,10);
    cout<<"k max Array"<<endl;
    prnt(kMaxAry,n,10);*/
    cout<<"The sum of all Hashed Cells = "<<sum(sumAry,n)<<endl;
    cout<<"Theoretical sum of all Hashed Cells = "<<theory<<endl;
    cout<<"The max number of Collisions = "<<max(kMaxAry,n)<<endl;
    cout<<n<<" = "<<sum(kMaxAry,n)<<endl;
    
    //Clean up and exit stage right
    delete []sumAry;
    delete []kMaxAry;
    
    return 0;
}

int  sum(int *a,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum;
}

int  max(int *a,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(a[i]>max)max=a[i];
    }
    return max;
}

void prnt(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl<<endl;
}

int *fill(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=0;
    }
    return array;
}