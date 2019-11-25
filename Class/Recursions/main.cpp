/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Date:   October 23nd, 2019
 * Purpose:All sorts of Recursions
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int bCoeff(int,int); //Binomial Coefficients
int gcd(int,int);    //Greatest Common Denominator
int factorial(int);  //Factorial
float sumLogN(int);  //Sum of the logs factorial
float tanRec(float); //Tangent function in recursive form
float sinRec(float); //Sin function in recursive form
float cosRec(float); //Cos function in recursive form
double sinRec(double); //Sin function in recursive form
double cosRec(double); //Cos function in recursive form
double expRec(double);   //Exponential function in recursive form

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    int num=63,den=294;
    int n=10;
    const float  PI=4*atan(1);
    const double DPI=4*atan(1);
    float thetaDeg=-30,thetaRad;//Angle in degrees
    double thetaDDeg=-30,thetaRRad;//Angle in degrees

    //Display the results
    cout<<n<<"! = "<<factorial(n)<<" = "<<exp(sumLogN(n))<<endl;
    
    int gcdVal=gcd(num,den);
    cout<<num<<"/"<<den<<" = "<<num/gcdVal<<"/"<<den/gcdVal<<endl<<endl;
    
    int nLoop=10;
    cout<<"Pascals Triangle"<<endl;
    for(int n=0;n<nLoop;n++){
        for(int j=0;j<=n;j++){
            cout<<bCoeff(n,j)<<" ";
        }
        cout<<endl;
    }
    
    //Compare the recursive tangent with cmath library
    thetaRad=thetaDeg*PI/180;//Output in radians
    thetaRRad=thetaDDeg*DPI/180;//Output in radians
    cout<<endl<<endl<<"Comparison of Trig functions"<<endl;
    cout<<"Recursive tan("<<thetaDeg<<" degrees) = "<<tanRec(thetaRad)<<endl;
    cout<<"CMATH     tan("<<thetaDeg<<" degrees) = "<<tan(thetaRad)<<endl;
    cout<<"Recursive sin("<<thetaDeg<<" degrees) = "<<sinRec(thetaRad)<<endl;
    cout<<"DoubleRec sin("<<thetaDDeg<<" degrees) = "<<sinRec(thetaRRad)<<endl;
    cout<<"CMATH     sin("<<thetaDeg<<" degrees) = "<<sin(thetaRad)<<endl;
    cout<<"Recursive cos("<<thetaDeg<<" degrees) = "<<cosRec(thetaRad)<<endl;
    cout<<"DoubleRec cos("<<thetaDDeg<<" degrees) = "<<cosRec(thetaRRad)<<endl;
    cout<<"CMATH     cos("<<thetaDeg<<" degrees) = "<<cos(thetaRad)<<endl;
    cout<<"Exponetialexp("<<thetaRRad<<")   = "<<expRec(thetaRRad)<<endl;
    cout<<"CMATH     exp("<<thetaRad<<")   = "<<exp(thetaRad)<<endl;

    
    //Clean up and exit stage right
    return 0;
}

double expRec(double x){
    //Base Case
    double tol=1e-6f;
    if(abs(x)<tol)return 1+x;
    //Recursive form
    double a=expRec(x/2);
    return a*a;
}

double cosRec(double theta){
    //Base Case
    double tol=1e-6f;
    if(abs(theta)<tol)return 1-theta*theta/2;
    //Recursion
    double a=sinRec(theta/2);
    double b=cosRec(theta/2);
    return b*b-a*a;
}

double sinRec(double theta){
    //Base Case
    double tol=1e-6f;
    if(abs(theta)<tol)return theta-theta*theta*theta/6;
    //Recursion
    return 2*sinRec(theta/2)*cosRec(theta/2);
}

float cosRec(float theta){
    //Base Case
    float tol=1e-6f;
    if(abs(theta)<tol)return 1-theta*theta/2;
    //Recursion
    float a=sinRec(theta/2);
    float b=cosRec(theta/2);
    return b*b-a*a;
}

float sinRec(float theta){
    //Base Case
    float tol=1e-6f;
    if(abs(theta)<tol)return theta-theta*theta*theta/6;
    //Recursion
    return 2*sinRec(theta/2)*cosRec(theta/2);
}

float tanRec(float theta){
    //Base Case
    float tol=1e-6f;
    if(abs(theta)<tol)return theta+theta*theta*theta/3;
    //Recursion
    float a=tanRec(theta/2);
    return 2*a/(1-a*a);
}

int bCoeff(int n,int j){
    //Base Case
    if(j==0)return 1;
    if(n==j)return 1;
    //Recursion
    return bCoeff(n-1,j-1)+bCoeff(n-1,j);
}

int gcd(int m,int n){
    //Base Case
    if(m==0)return n;
    //Recursion
    if(m>=n)return gcd(m%n,n);
    return gcd(n%m,m);
}

int factorial(int n){
    //Base Case
    if(n<=0)return 1;
    //Recursion
    return factorial(n-1)*n;
}

float sumLogN(int n){
    //Base Case
    if(n<=1)return log(1);
    //Recursion
    return sumLogN(n-1)+log(n);
}