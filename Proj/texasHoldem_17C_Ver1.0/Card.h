/* 
 * File:   Card.h
 * Author: Byoung Mo Lee
 * Created on May 16, 2019 23:52 PM
 * Purpose: Texas Holdem
 * 
 */

#ifndef CARD_H
#define CARD_H

#include <memory>

class Card{
protected:
    int face; //2~J(11),Q(12),K(13),A(14)
    int suit;  //0-Spades, 1-Hearts, 2-Diamonds, 3-Clubs
public:
    Card() {face=-1;suit=-1;}
    Card(int f,int s) {face=f;suit=s;}
    
    void setCard(int f,int s) {face=f;suit=s;}
    void setFace(int f) {face=f;}
    void setSuit(int s) {suit=s;}
    void setACard(Card &c) {setCard(c.face,c.suit);}
    int getFace() const {return face;}
    int getSuit() const {return suit;}
    void displayCard();  //defined in Card.cpp
    void selectionSortByFace(Card* c, int begin, int size);
    void selectionSortBySuit(Card* c, int begin, int size);
    const Card operator=(const Card &right){
        if(this != &right){
            face=right.face;
            suit=right.suit;
        }
        return *this;
    }
};


#endif /* CARD_H */

