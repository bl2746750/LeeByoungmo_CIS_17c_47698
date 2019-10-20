/* 
 * File:   Dealer.h
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 09:08 AM
 * Purpose: Texas Holdem
 * 
 */
#ifndef DEALER_H
#define DEALER_H

#include <string>
#include "Hands.h"


using namespace std;

class Dealer{  
private:
    int potAmount;
    int initialContributeAmount;
    int nRound;   //static
    int numPlayers;
    int bigBlind;
    int smallBlind;
    Hands* players;
    Card* deck[52];
    void DeckOfCards();
    
    
public:
    //class NegativeNumber {};
    Dealer(int num);
    ~Dealer() {}
    void shuffle();
    void setPlayers(int num);
    void setCards() {this->DeckOfCards();}
    void setBlind();
    int getBigBlind(){return this->bigBlind;}
    int getSmallBlind(){return this->smallBlind;}
    //void setMyCards(Card* mc) {myCards=mc;}
    void setRound() {this->nRound=0;}
    //void initiateRound();
    //int decideWinner();
    //void completeRound();
    void preflop();
    void flop();
    void turn();
    void river();
    //int getPotAmount() const {return potAmount;}
    //int getInitContAmount() const {return initialContributeAmount;}
    int getRound() const {return this->nRound;}
    Hands* getPlayers() const {return players;}
    Card** getDeck() {return this->deck;}
    int getNumPlayers() const {return numPlayers;}
    //void displayCards(Card* cards);
    void displayPlayersInfo(int num);
    int bettingPrompt1();
    void setIniCont() {this->initialContributeAmount=50;}
    void setPotAmount() {this->potAmount=0;}
    int bettingPrompt2(int num, int amount);
    int bettingPrompt3(int num, int amount);
    int getPotAmount() {return this->potAmount;}
    int getNumAct();
};

//int Dealer::round=0;

#endif /* DEALER_H */

