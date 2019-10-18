/* 
 * File:   Card.cpp
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 00:09 AM
 * Purpose: Texas Holdem
 * 
 */
#include <string>
#include <iostream>
#include "Card.h"
using namespace std;

void Card::displayCard(){
    string a[52]={"\U0001F0A1","\U0001F0A2","\U0001F0A3","\U0001F0A4","\U0001F0A5"
            ,"\U0001F0A6","\U0001F0A7","\U0001F0A8","\U0001F0A9","\U0001F0AA","\U0001F0AB"
            ,"\U0001F0AD","\U0001F0AE","\U0001F0B1","\U0001F0B2","\U0001F0B3","\U0001F0B4"
            ,"\U0001F0B5","\U0001F0B6","\U0001F0B7","\U0001F0B8","\U0001F0B9","\U0001F0BA"
            ,"\U0001F0BB","\U0001F0BD","\U0001F0BE","\U0001F0C1","\U0001F0C2","\U0001F0C3"
            ,"\U0001F0C4","\U0001F0C5","\U0001F0C6","\U0001F0C7","\U0001F0C8","\U0001F0C9"
            ,"\U0001F0CA","\U0001F0CB","\U0001F0CD","\U0001F0CE","\U0001F0D1","\U0001F0D2"
            ,"\U0001F0D3","\U0001F0D4","\U0001F0D5","\U0001F0D6","\U0001F0D7","\U0001F0D8"
            ,"\U0001F0D9","\U0001F0DA","\U0001F0DB","\U0001F0DD","\U0001F0DE"};
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(face==j+1 && suit==i) cout << a[i*13+j];
        }
    }
    if(face==14 && suit==0) cout << a[0];
    if(face==14 && suit==1) cout << a[13];
    if(face==14 && suit==2) cout << a[26];
    if(face==14 && suit==3) cout << a[39];
}

 void Card::selectionSortByFace(Card* c, int begin, int size){
     int minIndex, maxValue;
     int end=begin+size;
     for(int start=begin;start<end-1;start++){
         minIndex=start;
         maxValue=c[start].face;
         for(int index=start+1;index<end;index++){
             if(c[index].face>maxValue){
                 maxValue=c[index].face;
                 minIndex=index;
             }
         }
         swap(c[minIndex].face,c[start].face);
         swap(c[minIndex].suit,c[start].suit);
    }
 }
 
 void Card::selectionSortBySuit(Card* c, int begin, int size){
     int minIndex, maxValue;
     int end=begin+size;
     for(int start=begin;start<end-1;start++){
         minIndex=start;
         maxValue=c[start].suit;
         for(int index=start+1;index<end;index++){
             if(c[index].suit>maxValue){
                 maxValue=c[index].suit;
                 minIndex=index;
             }
         }
         swap(c[minIndex].face,c[start].face);
         swap(c[minIndex].suit,c[start].suit);
        }
 }