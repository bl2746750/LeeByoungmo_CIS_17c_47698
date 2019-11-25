/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 17th, 2019
 * Purpose:Compare Bloom Filter Theory with Empirical Computations
 */

//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
float Ekm(int,int);
float aEkm(int,int);
float exEkm(int,int);
float aprxEkm(int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int n;//Size of the Bloom Filter bit vector
    int m;//Number of elements in the list to include in the filter
    int k;//Number of hashes
    
    //Initialize Variables
    k=3;    //Number of Hashes
    m=10000;//Size of the Dictionary
    n=28*m;//Gives 1 in a 1000 error rate
    
    //Display the results
    cout<<"k="<<k<<" m="<<m<<" km="<<k*m
            <<" n="<<n<<" bytes="<<n/8<<endl;
    cout<<"Simulated Sum   = "<<aEkm(k*m,n)<<endl;
    cout<<"Recursive Sum   = "<<Ekm(k*m,n)<<endl;
    cout<<"Theoretical Sum = "<<exEkm(k*m,n)<<endl;
    cout<<"Approximate Sum = "<<aprxEkm(k*m,n)<<endl;

    //Clean up and exit stage right
    return 0;
}

float aprxEkm(int km,int n){
    return n*(1-exp(-1.0f*km/n));
}

float exEkm(int km,int n){
    return n*(1-pow((1-1.0/n),km));
}

float aEkm(int km,int n){
    int *array=new int[n];
    int sum=0;
    for(int i=0;i<n;i++){
        array[i]=0;
    }
    for(int i=0;i<km;i++){
        int hash=rand()%n;
        array[hash]=1;
    }
    for(int i=0;i<n;i++){
        sum+=array[i];
    }
    delete []array;
    return sum;
}

float Ekm(int km,int n){
    if(km<=0)return 0;
    if(km==1)return 1;
    return (1-1.0f/n)*Ekm(km-1,n)+1;
}