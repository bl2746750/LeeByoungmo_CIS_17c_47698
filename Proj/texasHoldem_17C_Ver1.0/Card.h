/* 
 * File:   Card.h
 * Author: Byoung Mo Lee
 * Created on May 16, 2019 23:52 PM
 * Purpose: Texas Holdem
 * 
 */

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card{
private:
    int number;
    int face; //2~J(11),Q(12),K(13),A(14)
    int suit;  //0-Spades, 1-Hearts, 2-Diamonds, 3-Clubs
    string faceName;
    string suitName;
    string picture;
public:
    
    Card(int num);
    
    void setFace();
    void setSuit();
    void setPict();
    int getFace() const {return this->face;}
    int getSuit() const {return this->suit;}
    string getFaceName() const {return this->faceName;}
    string getSuitName() const { return this->suitName;}
    string getPict() const {return this->picture;}
    int getNumber() const { return this->number;}
    void toString();
};


#endif /* CARD_H */

