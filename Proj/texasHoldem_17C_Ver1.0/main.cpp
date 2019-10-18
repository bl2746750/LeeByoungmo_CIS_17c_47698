/* 
 * File:   main.cpp
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 00:29 AM
 * Purpose: Texas Holdem
 * 
 */

//System Libraries Here
#include <iostream>//I/O Library
#include <cstdlib>   //Srand
#include <ctime>     //Time to set random number seed
#include <cmath>     //Math Library
#include <fstream> //file I/O Library 
#include <cctype>  //ch+10
#include <string>  //string library
#include <clocale> //print card library
#include "Card.h"


#include "Dealer.h"


using namespace std;

//User Libraries Here
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
//Structure



//Function Prototypes Here

//Execution begins here

void showNumPlayers(const Dealer *activity);
int main(int argc, char** argv) {
    int n=5;
    int exit=1;
    cout << "number of players: ";
    cin >> n;
    try{
        Dealer a(n);
    
    
        while(exit){

            a.shuffle();
            //a.display();
            a.dealPreflop();
            //a.display();
            a.dealFlop();
            //a.display();
            a.dealTurn();
            //a.display();
            a.dealRiver();
            a.display();
            showNumPlayers(&a);
            //a.getPlayers()[0].updateMyHands(a.getPlayers()[0]);
            //cout << a.getPlayers()[0].getHands() << endl;
            //cout << a.getPlayers()[0].getPoints() << endl;
            for(int i=0;i<n;i++){
                a.getPlayers()[i].resetMyCards();
            }

            






            cout << "Press 1 to continue or press 0 to exit!!!" << endl;
            cin >> exit;
        }
    }
    catch (Dealer::NegativeNumber){
    cout << "Error: number should be positive.\n";
    }
    
    return 0;
}

void showNumPlayers(const Dealer *activity){
    int num=activity->getNumPlayers();
    cout << num << " players are playing now!" << endl;
}