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
    
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << endl;
    
    auto t2=std::make_tuple(22,44,"nico");
    
    
    cout << get<0>(t2) << " ";
    cout << get<1>(t2) << " ";
    cout << get<2>(t2) << " ";
    cout << endl;
    
    
    get<1>(t1)=get<1>(t2);
    
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << endl;
    
    cout << get<0>(t2) << " ";
    cout << get<1>(t2) << " ";
    cout << get<2>(t2) << " ";
    cout << endl;
    
    
    if(t1<t2){t1=t2;}
    
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << endl;
    
    cout << get<0>(t2) << " ";
    cout << get<1>(t2) << " ";
    cout << get<2>(t2) << " ";
    cout << endl;
    
    return 0;
}

