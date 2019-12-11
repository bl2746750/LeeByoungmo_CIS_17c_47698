/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Date:   Nov 1st, 2019 21:48 PM
 * Purpose:prob 10
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
const double PI=4*atan(1);
//Function Prototypes
float prob10(float,int);
double prob11(double);
double prob12_C(double); 
double prob12_S(double);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float x=30.5;
    double y=0.5;
    double z=PI/4;
    int n=5;
    
    //Initialize Variables
    
    //Process inputs to outputs/map and Display
        
    //Output 
    cout << "Problem10: (1) x=30.5, n=5 (2) x^n= " << prob10(x,n) << endl;
    cout << "Problem11: (1) x=0.5 (2) g(x)= " << prob11(y) << endl;
    cout << "Problem12: (1) x=PI/4 (2) C(x)= " << prob12_C(z);
    cout << ", S(x)= " << prob12_S(z) << endl;
    //Clean up and exit stage right
    return 0;
}

float prob10(float x,int n){
    //base case
    if(n==1) return x;
    else if(n%2==0) return prob10(x,n/2)*prob10(x,n/2);
    else if(n%2==1) return prob10(x,(n-1)/2)*prob10(x,(n-1)/2)*x;
    
}

double prob11(double x){
    double y=x/2;
    //base case
    double tol=1e-6f;
    if(abs(y)<tol) return y-y*y*y/6;
    return 2*prob11(y)/(1+prob11(y)*prob11(y));
}
double prob12_C(double x){
    double y=x/2;
    //base case
    double tol=1e-6f;
    if(abs(x)<tol) return 1/x+x/6;
    return 0.5*(prob12_C(y)*prob12_S(y));
}
double prob12_S(double x){  
    double y=x/2;
    //base case
    double tol=1e-6f;
    if(abs(x)<tol) return 1+x*x/2;
    double a=prob12_C(y);
    double b=prob12_S(y);
    return a*a*b*b/(a*a-b*b);
}
