/* 
 * File:   newmain.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 11, 2011, 9:26 AM
 * Purpose:  Mark Sort in 3 routines
 */

//System Libraries
#include <cstdlib>  //Random Function
#include <iostream> //I/O
#include <ctime>    //Set the seed
using namespace std;

//User Libraries

//Global Constants
//Math/Physics/Conversion/Higher Order Dimensions
double opeq,oplt,opinc,opexor,opindex,opmin,opgt,opplus;

//Function Prototypes
int *fillAry(int);
void prntAry(int *,int,int);
void markSrt(int *,int);

//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *array;
    int size=40000;
    int perLine=20;
    opeq=oplt=opinc=opexor=opindex=opmin=opgt=opplus=0;
    
    //Initialize/Input Data/Variables
    array=fillAry(size);

    //Display output
    //prntAry(array,size,perLine);
    
    //Sort
    markSrt(array,size);
    
    //Display output
    //prntAry(array,size,perLine);
    cout<<"# of eq operations    = "<<opeq<<endl;
    cout<<"# of lt operations    = "<<oplt<<endl;
    cout<<"# of inc operations   = "<<opinc<<endl;
    cout<<"# of exor operations  = "<<opexor<<endl;
    cout<<"# of index operations = "<<opindex<<endl;
    cout<<"# of minus operations = "<<opmin<<endl;
    cout<<"# of gt operations    = "<<opgt<<endl;
    cout<<"# of plus operations  = "<<opplus<<endl;
    float optot=opeq+oplt+opinc+opexor+opindex+opmin+opgt+opplus;
    cout<<"# of tot operations   = "<<optot<<endl;
    
    
    //Clean up dynamic memory
    delete []array;
    
    //Exit program
    return 0;
}

void markSrt(int *a,int n){
    opeq+=1;oplt+=1;opmin+=1;
    for(int i=0;i<n-1;i++){//Find Smallest for each list
        oplt+=2;opmin+=1;opinc+=1;
        opeq+=1;opplus+=1;
        for(int j=i+1;j<n;j++){//Examine each element below top of list
            oplt+=1;opinc+=1;
            //Swap
            opgt+=1;
            opindex+=2;
            if(a[i]>a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
                opexor+=3;
                opeq+=3;
                opindex+=9;
            }
        }
    }
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand();
    }
    return array;
}