/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Purpose: Learing Tuple (p.68)
 * Created on October 9, 2019, 4:10 PM
 */

#include <tuple>
#include <iostream>
#include <complex>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    tuple<string,int,int,complex<double>> t;
    
    tuple<int,float,string> t1(41,6.3,"nico");
    
    return 0;
}

