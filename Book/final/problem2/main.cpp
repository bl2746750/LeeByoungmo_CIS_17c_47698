/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Dec 2, 2019, 8:11 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
using namespace std;

double PI=atan(1)*4;
int callH=0;
int callG=0;


float h(float);
float g(float);

int main(int argc, char** argv) {
    //Testing out recursive trig functions
    float angDeg=-180/PI;
    float angRad=-1;
    float inc=0.1;
    for(int i=0;i<21;i++){
        
        cout << asinh(1e-6) << endl;
        cout << acosh(1e-6) << endl;
        cout<<" Angle Radian = " << angRad << " ,sinh = "<<sinh(angRad)<<
                " ,our h = "<<h(angRad)<< " ,# of call h function = " << callH << endl;
        cout<<" Angle Radian = " << angRad <<", cosh = "<<cosh(angRad)<<
                " ,our g = "<<g(angRad)<< " ,# of call g function = " << callG<<endl;
        cout << "_____________________________________________________________________" << endl;
        callH=0;
        callG=0;
        angRad+=inc;
    }
    //Exit stage right
    return 0;
}

float h(float angR){
    float tol=1e-6;
    callH++;
    if(angR>-tol&&angR<tol){
        return angR+angR*angR*angR/6;
    }
    return 2*h(angR/2)*g(angR/2);
}
float g(float angR){
    float tol=1e-6;
    callG++;
    if(angR>-tol&&angR<tol){
        return 1+angR*angR/2;
    }
    float b=h(angR/2);
    return 1+2*b*b;
}
