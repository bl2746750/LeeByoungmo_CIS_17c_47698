/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:    October 30, 2019
 * Purpose: More Recursions
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
const float PI=4*atan(1);
const float CNVRADEG=PI/180;

//Function Prototypes
float tanRec(float);
double cosRec(double);
double sinRec(double);
float expRec(float);
double expRec(double);
float fValue(float,float,int);
void hanoi(int,int,int,int);
int maxRec(int *,int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float thetaDeg=30,thetaRad,fx,pv=100,intRate=0.06f;
    double dx;
    int n=12;
    int a1[]={5,4,3,2,1,7,1,2,3,4,5,6};
    int a2[]={2,3,5,4,1};
    int a3[]={1,2,3,4,5};
    
    //Initialize Variables
    thetaRad=thetaDeg*CNVRADEG;
    fx=1;
    dx=1;
    
    //Process inputs to outputs/map and Display
    cout<<"Recursive tan("<<thetaDeg<<")="<<tanRec(thetaRad)<<endl;
    cout<<"CMATH     tan("<<thetaDeg<<")="<<tan(thetaRad)<<endl;
    cout<<"Recursive cos("<<thetaDeg<<")="<<cosRec(thetaRad)<<endl;
    cout<<"CMATH     cos("<<thetaDeg<<")="<<cos(thetaRad)<<endl;
    cout<<"Recursive sin("<<thetaDeg<<")="<<sinRec(thetaRad)<<endl;
    cout<<"CMATH     sin("<<thetaDeg<<")="<<sin(thetaRad)<<endl;
    cout<<"Recursive Float  exp("<<fx<<")="<<expRec(fx)<<endl;
    cout<<"Recursive Double exp("<<dx<<")="<<expRec(dx)<<endl;
    cout<<"CMATH            exp("<<fx<<")="<<exp(fx)<<endl;
    cout<<"Future Value("<<pv<<","
            <<intRate<<","<<n<<")="<<fValue(pv,intRate,n)<<endl;
    intRate=0.08f;n=9;
    cout<<"Future Value("<<pv<<","
            <<intRate<<","<<n<<")="<<fValue(pv,intRate,n)<<endl;
    intRate=0.09f;n=8;
    cout<<"Future Value("<<pv<<","
            <<intRate<<","<<n<<")="<<fValue(pv,intRate,n)<<endl;
    intRate=0.12f;n=6;
    cout<<"Future Value("<<pv<<","
            <<intRate<<","<<n<<")="<<fValue(pv,intRate,n)<<endl;
    intRate=0.03f;n=24;
    cout<<"Future Value("<<pv<<","
            <<intRate<<","<<n<<")="<<fValue(pv,intRate,n)<<endl;
    intRate=0.24f;n=3;
    cout<<"Future Value("<<pv<<","
            <<intRate<<","<<n<<")="<<fValue(pv,intRate,n)<<endl;
    
    //Call the hanoi function
    cout<<endl<<"The Towers of Hanoi solution"<<endl;
    hanoi(4,1,2,3);
    
    //Find the maximum in each array
    cout<<"The max value in each array"<<endl;
    int arraySz=sizeof(a1)/sizeof(int);
    cout<<"The size of the array 1 = "<<arraySz<<endl;
    cout<<"Max Value in Array 1 = "<<maxRec(a1,0,sizeof(a1)/sizeof(int))<<endl;
    cout<<"Max Value in Array 2 = "<<maxRec(a2,0,sizeof(a2)/sizeof(int))<<endl;
    cout<<"Max Value in Array 3 = "<<maxRec(a3,0,sizeof(a3)/sizeof(int))<<endl;

    //Clean up and exit stage right
    return 0;
}

int maxRec(int *a,int beg,int end){
    if(end-beg<=1)return a[beg];
    int half=(beg+end)/2;
    int m1=maxRec(a,beg,half);
    int m2=maxRec(a,half,end);
    return (m1>m2?m1:m2);
}

void hanoi(int nDisks,int src,int spare,int dest){
    if(nDisks>1)hanoi(nDisks-1,src,dest,spare);
    cout<<"Move -> "<<src<<" to -> "<<dest<<endl;
    if(nDisks>1)hanoi(nDisks-1,spare,src,dest);
}

float fValue(float pv,float i,int n){
    //Base Case
    if(n<=0)return pv;
    //Recursion
    return fValue(pv,i,n-1)*(1+i);
}

double expRec(double x){
    //Base Case
    double tol=1e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursion
    double exp=expRec(x/2);
    return exp*exp;
}

float expRec(float x){
    //Base Case
    float tol=1e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursion
    float exp=expRec(x/2);
    return exp*exp;
}

double cosRec(double angle){
    //Base Case
    double tol=1e-6f;
    if(abs(angle)<tol)return 1-angle*angle/2;
    //Recursion
    double sin=sinRec(angle/2);
    double cos=cosRec(angle/2);
    return cos*cos-sin*sin;
}

double sinRec(double angle){
    //Base Case
    double tol=1e-6f;
    if(abs(angle)<tol)return angle-angle*angle*angle/6;
    //Recursion
    double sin=sinRec(angle/2);
    double cos=cosRec(angle/2);
    return 2*sin*cos;
}

float tanRec(float angle){
    //Base Case
    float tol=1e-6f;
    if(abs(angle)<tol)return angle+angle*angle*angle/3;
    //Recursion
    float tan=tanRec(angle/2);
    return 2*tan/(1-tan*tan);
}