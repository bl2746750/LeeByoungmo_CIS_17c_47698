/* 
 * File:   Hands.h
 * Author: Byoung Mo Lee
 * Created on May 18, 2019 20:43 PM
 * Purpose: Hands Class for Texas Holdem
 * 
 */


#ifndef HANDS_H
#define HANDS_H

#include <map>
#include "Player.h"
 
using namespace std;


class Hands : public Player{
private:
    int hands;
    string handsName;
    multimap<int,int, greater<int>> faces;
    map<int,int,greater<int>> suits;
    int isStraight;
    int isFlush;
    int isPair;
    int isStFl;

public:
    //Default constructor
    Hands();
    Hands(const Hands& orig);
    virtual~Hands(){
        
    }
    void setFaces();
    void setSuits();
    void checkStraight();
    multimap<int,int,greater<int>> getFaces(){return this->faces;}
    map<int,int,greater<int>> getSuits() {return this->suits;}
    int getHands();
    string getHandsName();
    void resetHands(){
        this->resetMyCards();
        this->faces.clear();
        this->suits.clear();
        this->hands=0;
        this->handsName="";
        this->isStraight=0;
        this->isFlush=0;
        this->isPair=0;
        this->isStFl=0;
    }
};    

#endif /* HANDS_H */

// hands=0: Highcard
// hands=1: One Pair
// hands=2: Two Pair
// hands=3: Three of a card
// hands=4: Straight
// hands=5: Flush
// hands=6: Full house
// hands=7: Four of a card
// hands=8: Straight Flush
