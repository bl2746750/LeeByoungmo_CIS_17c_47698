/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Date: October 28, 2019 22:36 PM
 * Purpose: Problem 9
 */

//System Libraries
#include <iostream>
#include <random>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    cout << "a) (1) p = Probability getting Head = 3/10, q = Probability getting tail = 7/10" << endl;
    cout << "   (2) (p+q)^n = (sigma sign) from i=0 to i=n (n i) p^i * q^(n-i) = 1" << endl;
    cout << "        (n i) is n choose i combination" << endl;
    cout << "   (3) So, if we substitute i=5, n=5, p=0.3, q=0.7" << endl;
    cout << "       then (0.3)^5 * (0.7)^0 = 0.00243, that is, 0.243%" << endl;
    
    //Set random number seed here
    
    //Declare Variables
    default_random_engine dre1;
    bernoulli_distribution di1(0.3);
    int N=1000000;
    int head=0;
    int tail=0;
    int count=0;
    //Initialize Variables
    
    //Process inputs to outputs/map
    for(int i=0;i<N;++i){
        for(int j=0;j<5;j++){
            if(di1(dre1)) head++;
            else tail++;
            if(head==5) count++; 
        }
        head=0;
        tail=0;
    }
    
    //Display the results
    cout << "b) Simulation result:" << count*1.0/N*100 << "%" << endl;
    
    //Clean up and exit stage right
    return 0;
}