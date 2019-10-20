/*
 * File:   main.cpp
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 00:29 AM
 * Purpose: Texas Holdem
 *
 */

//System Libraries Here

#include <iostream>
#include <iterator>
#include "Dealer.h"


using namespace std;

//User Libraries Here
//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
//Structure



//Function Prototypes Here

//Execution begins here


int main(int argc, char** argv) {
    Dealer game(3);
//    game.Dealer::setCards();
//    for(int i=0;i<52;i++){
//        cout << game.getDeck()[i]->getPict();
//    }
//    cout << endl;
//    game.shuffle();
//    for(int i=0;i<52;i++){
//        cout << game.getDeck()[i]->getPict();
//    }
//    cout << endl << endl;
//
//    game.Preflop();
    
//    cout << game.getPlayers()[0].getMyCards().front().getPict() << endl;
//    cout << game.getPlayers()[0].getMyCards().back().getPict() << endl;
    
   
    
//    cout << game.getPlayers()[0].getMyCards().back().getPict() << endl;
//            
//    list<Card*>::iterator it=game.getPlayers()[0].getMyCards().begin();
//    cout << *it->getPict() << endl;
//    Card* deck[52];
//    for(int i=0;i<52;i++){
//        deck[i]=new Card(i);
//    }
//    list<Card> test;
//    Card card=*deck[3];
//    test.push_back(card);
//    cout << test.back().getPict() << endl;
    return 0;
}
