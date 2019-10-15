/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Date: October 14, 2019 15:54 PM
 * Purpose: LabBinomial Theorem
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
    cout << "a) (1) p = Probability getting Head = 1/2, q = Probability getting tail = 1/2" << endl;
    cout << "   (2) (p+q)^n = (sigma sign) from i=0 to i=n (n i) p^i * q^(n-i) = 1" << endl;
    cout << "        (n i) is n choose k combination" << endl;
    cout << "   (3) So, if we substitute i=1, n=4, p=0.5, q=0.5" << endl;
    cout << "       then 4*(0.5)^1 * (0.5)^(4-1) = 0.25" << endl;
    
    //Set random number seed here
    
    //Declare Variables
    default_random_engine dre1,dre2,dre3,dre4;
    bernoulli_distribution di1(0.5);
    bernoulli_distribution di2(0.6);
    int sumFirstTail=0,sumSecTail=0,sumThirdTail=0,sumFourthTail=0,sum;
    float pFirstOne, pSecOne, pThirdOne, pFourthOne;
    int N=10000;
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    for(int i=0;i<N;++i){
        
        if(!di1(dre1)&&di1(dre2)&&di1(dre3)&&di1(dre4)) sumFirstTail++;
        if(di1(dre1)&&!di1(dre2)&&di1(dre3)&&di1(dre4)) sumSecTail++;
        if(di1(dre1)&&di1(dre2)&&!di1(dre3)&&di1(dre4)) sumThirdTail++;
        if(di1(dre1)&&di1(dre2)&&di1(dre3)&&!di1(dre4)) sumFourthTail++;
    }
    sum=sumFirstTail+ sumSecTail+ sumThirdTail+ sumFourthTail;
    //Display the results
    cout << "b) Simulation result:" << sum*1.0/N << endl;
    
    sum=0;
    sumFirstTail=0;
    sumSecTail=0;
    sumThirdTail=0;
    sumFourthTail=0;
    for(int i=0;i<N;++i){
        
        if(!di2(dre1)&&di2(dre2)&&di2(dre3)&&di2(dre4)) sumFirstTail++;
        if(di2(dre1)&&!di2(dre2)&&di2(dre3)&&di2(dre4)) sumSecTail++;
        if(di2(dre1)&&di2(dre2)&&!di2(dre3)&&di2(dre4)) sumThirdTail++;
        if(di2(dre1)&&di2(dre2)&&di2(dre3)&&!di2(dre4)) sumFourthTail++;
    }
    sum=sumFirstTail+ sumSecTail+ sumThirdTail+ sumFourthTail;
    cout << "c) (1) If we substitute i=1, n=4, p=0.4, q=0.6" << endl;
    cout << "       then 4*(0.4)^1 * (0.6)^(4-1) = 0.3456" << endl;
    cout << "   (2) Simulation result:" << sum*1.0/N << endl;
    //Clean up and exit stage right
    return 0;
}