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
#include "Card.h"
#include "Hands.h"

using namespace std;

class Player : public Hands  {
protected:
    string name;
    int balance;
    int order;      //if(order==0) Big blind, if(order==1) small blind
    int status;
    Card* myCards;
    Card* myFiveCards;
    int hands;
    int myPoints;
    
public:
    Player() {setPlayer("",10000,0,1);myCards=new Card[7];}
    ~Player() {}
    void setPlayer(string n,int b, int o, int s) {name=n;balance=b;order=o;status=s;}
    void setMyCard(Card* mC) {myCards=new Card[7];myCards=mC;}
    void setName(string n) {name=n;}
    void setBalance(int b) {balance=b;}
    void setOrder(int o) {order=o;}
    void setStatus(int s) {status=s;}
    string getName() const {return name;}
    int getBalance() const {return balance;}
    int getNumCards() const;
    void updateMyHands();
    int getMyHands() const;
    Card* getMyFiveCards() const;
    int getMyPoints() const;
    int getOrder() const {return order;}
    Card* getMycards() const {return myCards;}
    int getStatus() const {return status;}
    void putMoneyToPot(int m) {balance-=m;}
    void takeMoneyFromPot(int m) {balance+=m;}
    void resetMyCards() {delete [] myCards;myCards= new Card [7];}
    void addCards(Card *c, int n); //mC=players.myCards, c=decked Cards, n=number of addition
    void displayMyFiveCards();
    
};

#endif /* PLAYER_H */

