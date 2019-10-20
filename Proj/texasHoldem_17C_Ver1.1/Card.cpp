/* 
 * File:   Card.cpp
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 00:09 AM
 * Purpose: Texas Holdem
 * 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include "Card.h"
using namespace std;

Card::Card(int num){
    if(num>=0&&num<52){
        this->number=num;
        this->setFace();
        this->setSuit();
        this->setPict();
    }
    else{
        this->number=-1;
        this->face=-1;
        this->suit=-1;
        this->faceName="none";
        this->suitName="none";
        this->picture="none";
    }
}

void Card::setFace(){
    if(this->number%13+1==1) {this->face=14;}
    else{this->face=this->number%13+1;}
    
    switch (this->face) {
            case 2: this->faceName = "two";break;
            case 3: this->faceName = "three";break;
            case 4: this->faceName = "four";break;
            case 5: this->faceName = "five";break;
            case 6: this->faceName = "six";break;
            case 7: this->faceName = "seven";break;
            case 8: this->faceName = "eight";break;
            case 9: this->faceName = "nine";break;
            case 10: this->faceName = "ten";break;
            case 11: this->faceName = "jack";break;
            case 12: this->faceName = "queen";break;
            case 13: this->faceName= "king";break;
            case 14: this->faceName = "ace";break;
            default: this->faceName = "Bad Value";
        }
}

void Card::setSuit(){
    if(this->number<13){
        this->suit=0;
        this->suitName="spades";
    }
    else if(this->number<26){
        this->suit=1;
        this->suitName="hearts";
    }
    else if(this->number<39){
        this->suit=2;
        this->suitName="diamonds";
    }
    else if(this->number<52){
        this->suit=3;
        this->suitName="clubs";
    }
    else{
        this->suit=-1;
        this->suitName="Bad Value";
    }
}

void Card::setPict(){
             
    string a[52]={"\U0001F0A1","\U0001F0A2","\U0001F0A3","\U0001F0A4","\U0001F0A5"
            ,"\U0001F0A6","\U0001F0A7","\U0001F0A8","\U0001F0A9","\U0001F0AA","\U0001F0AB"
            ,"\U0001F0AD","\U0001F0AE","\U0001F0B1","\U0001F0B2","\U0001F0B3","\U0001F0B4"
            ,"\U0001F0B5","\U0001F0B6","\U0001F0B7","\U0001F0B8","\U0001F0B9","\U0001F0BA"
            ,"\U0001F0BB","\U0001F0BD","\U0001F0BE","\U0001F0C1","\U0001F0C2","\U0001F0C3"
            ,"\U0001F0C4","\U0001F0C5","\U0001F0C6","\U0001F0C7","\U0001F0C8","\U0001F0C9"
            ,"\U0001F0CA","\U0001F0CB","\U0001F0CD","\U0001F0CE","\U0001F0D1","\U0001F0D2"
            ,"\U0001F0D3","\U0001F0D4","\U0001F0D5","\U0001F0D6","\U0001F0D7","\U0001F0D8"
            ,"\U0001F0D9","\U0001F0DA","\U0001F0DB","\U0001F0DD","\U0001F0DE"};
    
    for(int i=0;i<52;i++){
        if(this->number==i) this->picture=a[i];
    }
}

void Card::toString(){
    cout << this->Card::getPict() << " ";
    //cout << this->Card::getFace() << " ";
    //cout << this->Card::getSuit() << " ";
    cout << this->Card::getFaceName() << " ";
    cout << this->Card::getSuitName() << endl;
}
