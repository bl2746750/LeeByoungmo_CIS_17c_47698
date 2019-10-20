/* 
 * File:   Player.h
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 10:16 AM
 * Purpose: Player Class for Texas Holdem
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <list>
#include "Card.h"


using namespace std;

class Player {
private:
    string name;
    int balance;
    int inThePot;
    bool active;
    list<Card> myCards;
    
public:
    Player();
    ~Player() {}
    void setPlayerName(string name) {this->name=name;}
    void setPlayerBal() {this->balance=1000;}
    void addMyCards(Card card);
    void setPlayerAct() {this->active=1;}
    string getName() const {return this->name;}
    int getBalance() const {return this->balance;}
    int getPlayerAct() {return this->active;}
    list<Card> getMyCards() {return this->myCards;}
    void bet(int amount) {this->balance -=amount;this->inThePot +=amount;}
    void setPlayerInact() {this->active=0;}
    void setInThePot() {this->inThePot=0;}
    int putInThePot() {return this->inThePot;}
    bool getActStatus() {return this->active;}
    
    
};

#endif /* PLAYER_H */

