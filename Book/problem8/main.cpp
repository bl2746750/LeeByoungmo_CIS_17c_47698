/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Date: October 28, 2019 14:38 PM
 * Purpose: midterm problem 8
 */

//System Libraries
#include <iostream>
#include <random>
#include <set>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int roll_a_fair_die( )
{
     static std::default_random_engine e{};
     static std::uniform_int_distribution<int> d{1, 6};
     return d(e);
}

int checkPair(int array[], int size){
    int isPair=0;
    multiset<int> faceSet;
    for(int i=0;i<size;i++){
        faceSet.insert(array[i]);
    }
    
    for(int i=1;i<=6;i++){
        if(faceSet.count(i)==2) isPair++;
        else if(faceSet.count(i)==3) isPair=3;
        else if(faceSet.count(i)==4) isPair=4;
    }
    
    faceSet.clear();
    
    return isPair;
}
//Execution Begins Here
int main(int argc, char** argv) {
    
    
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    int N=1000;
    int** diceAry=new int* [N];
    int aPair=0;
    int twoPair=0;
    int triple=0;
    int four=0;
    int check;
    
    //Initialize Variables
    
    //Process inputs to outputs/map
    //Display the results
    for(int i=0;i<N;i++){
        diceAry[i]=new int [4];
        for(int j=0;j<4;j++){
            diceAry[i][j]=rand()%6+1;
//            cout << diceAry[i][j] << " ";
        }
//        cout << " pair: " << checkPair(diceAry[i],4) << endl;
        check=checkPair(diceAry[i],4);
        if(check==1) aPair++;
        else if(check==2) twoPair++;
        else if(check==3) triple++;
        else if(check==4) four++;
    }
    
    cout << "    Pair       " << "  number of event  "  << "    %    " << "Theoretical" << endl;
    cout << "  a Pair       " << "    " << aPair   << "              " << 1.0*aPair/N*100 << 
            "     " << 720.0/1296*100 <<endl;
    cout << " two Pairs     " << "    " << twoPair << "                " << 1.0*twoPair/N*100 << 
            "     " << 90.0/1296*100 <<endl;
    cout << "three of a kind" << "    " << triple  << "                " << 1.0*triple/N*100 << 
            "     " << 120.0/1296*100 << endl;
    cout << "four of a kind " << "    " << four    << "                 " << 1.0*four/N*100 <<
            "     " << 6.0/1296*100 <<endl;
    //Clean up and exit stage right
    return 0;
}