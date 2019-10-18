/* 
 * File:   Hands.h
 * Author: Byoung Mo Lee
 * Created on May 18, 2019 20:43 PM
 * Purpose: Hands Class for Texas Holdem
 * 
 */


#ifndef HANDS_H
#define HANDS_H


#include "Card.h"
 
using namespace std;


class Hands : public Card{
public:
    //Default constructor
    Hands();
    Hands(const Hands& orig);
    virtual ~Hands(){
        delete[] fiveCards;
        for(int i=0;i<faceRow;i++){
            delete[] faceSum[i];
        }
        delete[] faceSum;

        for(int i=0;i<suitRow;i++){
            delete[] suitSum[i];
        }
        delete[] suitSum;
    }
    
    int checkStraight(const int* const*, int);
    int isFlush(Card* );
    void checkFaceHands(Card*,int);
    void setHands(Card*,int );
    void setPoints(Card* c,int n);
    void displayFiveCards(Card*, int);
    Card* getFiveCards(Card* c,int n) {setHands(c, n);return fiveCards;}
    int getPoints(Card* c,int n) {return points;}
    int getHands(Card* c,int n) {setHands(c,n);return hands;}
    
    
private:
    Card* fiveCards;  //select 5 of 7 
    int hands;
    int points;
    
    struct{
        int** faceSum;
        int faceRow;
        int** suitSum;
        int suitRow;
        
    
    };
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
