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
double prob12_C(double); //not solved yet
double prob12_S(double);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float x=30.5;
    double y=0.5;
    double z=PI/4;
    int n=2;
    
    //Initialize Variables
    
    //Process inputs to outputs/map and Display
        
    //Output 
//    cout << prob10(x,n) << endl;
//    cout << prob11(y) << endl;
    cout << prob12_C(z) << endl;
    cout << prob12_S(z) << endl;
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
    return 4*prob12_C(x)*prob12_C(x)/(prob12_C(y)*prob12_C(y)-prob12_S(y)*prob12_S(y));
}
//int maxLin(int *a,int n){
//    int max=a[0];
//    for(int i=1;i<n;i++){
//        if(max<a[i])max=a[i];
//    }
//    return max;
//}
//
//int maxRec(int *a,int beg,int end){
//    if(end-beg<=1)return a[beg];
//    int half=(end+beg)/2;
//    int m1=maxRec(a,beg,half);
//    int m2=maxRec(a,half,end);
//    return (m1<m2?m2:m1);
//}
//
//void hanoi(int nDisks,int src,int spare,int dest ){
//    if(nDisks>1)hanoi(nDisks-1,src,dest,spare);
//    cout<<"Move -> "<<src<<" to -> "<<dest<<endl;
//    if(nDisks>1)hanoi(nDisks-1,spare,src,dest);
//}
//
//float fv(float pv,float i,int n){
//    //Base Case
//    if(n<=0)return pv;
//    //Recursion
//    return fv(pv,i,n-1)*(1+i);
//}
//
//double expRec(double x){
//    //Base Case
//    double tol=1e-6f;
//    if(abs(x)<tol)return 1+x;
//    //Recursive form
//    double a=expRec(x/2);
//    return a*a;
//}
//
//double cosRec(double theta){
//    //Base Case
//    double tol=1e-6f;
//    if(abs(theta)<tol)return 1-theta*theta/2;
//    //Recursion
//    double a=sinRec(theta/2);
//    double b=cosRec(theta/2);
//    return b*b-a*a;
//}
//
//double sinRec(double theta){
//    //Base Case
//    double tol=1e-6f;
//    if(abs(theta)<tol)return theta-theta*theta*theta/6;
//    //Recursion
//    return 2*sinRec(theta/2)*cosRec(theta/2);
//}
//
//float cosRec(float theta){
//    //Base Case
//    float tol=1e-6f;
//    if(abs(theta)<tol)return 1-theta*theta/2;
//    //Recursion
//    float a=sinRec(theta/2);
//    float b=cosRec(theta/2);
//    return b*b-a*a;
//}
//
//float sinRec(float theta){
//    //Base Case
//    float tol=1e-6f;
//    if(abs(theta)<tol)return theta-theta*theta*theta/6;
//    //Recursion
//    return 2*sinRec(theta/2)*cosRec(theta/2);
//}
//
//float tanRec(float theta){
//    //Base Case
//    float tol=1e-6f;
//    if(abs(theta)<tol)return theta+theta*theta*theta/3;
//    //Recursion
//    float a=tanRec(theta/2);
//    return 2*a/(1-a*a);
//}
//
//int bCoeff(int n,int j){
//    //Base Case
//    if(j==0)return 1;
//    if(n==j)return 1;
//    //Recursion
//    return bCoeff(n-1,j-1)+bCoeff(n-1,j);
//}
//
//int gcd(int m,int n){
//    //Base Case
//    if(m==0)return n;
//    //Recursion
//    if(m>=n)return gcd(m%n,n);
//    return gcd(n%m,m);
//}
//
//int factorial(int n){
//    //Base Case
//    if(n<=0)return 1;
//    //Recursion
//    return factorial(n-1)*n;
//}
//
//float sumLogN(int n){
//    //Base Case
//    if(n<=1)return log(1);
//    //Recursion
//    return sumLogN(n-1)+log(n);
//}