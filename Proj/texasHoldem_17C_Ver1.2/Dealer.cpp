/* 
 * File:   Dealer.cpp
 * Author: Byoung Mo Lee
 * Created on May 17, 2019 00:19 AM
 * Purpose: Texas Holdem
 * 
 */
#include <string>
#include <iostream>
#include <cstdlib>
#include "Dealer.h"

using namespace std;
Dealer::Dealer(int num){
    this->setPlayers(num);
    this->setBlind();
    this->setIniCont();
    this->setPotAmount();
    this->DeckOfCards();
    this->shuffle();
    this->preflop();
    this->flop();
    this->turn();
    this->river();
//    for(int i=0;i<this->numPlayers;i++){
//        int order=(i+this->bigBlind)%this->numPlayers;
//        this->Dealer::displayPlayersInfo(order);
//    }
//    int amount=bettingPrompt1();
//    cout << "bettingPrompt1 is Done" << endl;
////    for(int i=0;i<this->numPlayers;i++){
////        cout << this->players[i].getBalance() << endl;
////    }
////    cout << this->potAmount << endl;
//    
//    
//    int cnt=1;
//    int nP=this->numPlayers;
//    int x=1;
//    
//    do{
//        
//        amount=this->bettingPrompt2((cnt+this->smallBlind)%nP,amount);
//        if((cnt+this->bigBlind)%nP==this->bigBlind) x=0;
//        if(this->Dealer::getNumAct()==1) {
//            cout << "find the winner and terminate the round" << endl;
//            x=0;
//        }
//        cnt++;
//    }while(amount-this->players[(cnt+this->smallBlind)%nP].putInThePot()||x);
//    cout << "bettingPrompt2 is Done" << endl;
//    
//    this->flop();
//    cnt=0;
//    x=1;
//    while((amount-this->players[(cnt+this->bigBlind)%nP].putInThePot())||x){
//        int aP=this->Dealer::getNumAct();
//        amount=this->bettingPrompt3((cnt+this->bigBlind)%nP,amount);
//        cnt++;
//        if((cnt+this->bigBlind)%nP==this->bigBlind) x=0;
//        if(this->Dealer::getNumAct()==1) {
//            cout << "find the winner" << endl;
//            x=0;
//        }
//        
//    }
//    cout << "bettingPrompt3 is Done" << endl;
//    
//    this->turn();
//    
//    cnt=0;
//    x=1;
//    while((amount-this->players[(cnt+this->bigBlind)%nP].putInThePot())||x){
//        int aP=this->Dealer::getNumAct();
//        amount=this->bettingPrompt3((cnt+this->bigBlind)%nP,amount);
//        cnt++;
//        if((cnt+this->bigBlind)%nP==this->bigBlind) x=0;
//        if(this->Dealer::getNumAct()==1) {
//            cout << "find the winner" << endl;
//            x=0;
//        }
//        
//    }
//    cout << "bettingPrompt3 is Done" << endl;
//    
//    this->river();
//    cnt=0;
//    x=1;
//    while((amount-this->players[(cnt+this->bigBlind)%nP].putInThePot())||x){
//        int aP=this->Dealer::getNumAct();
//        amount=this->bettingPrompt3((cnt+this->bigBlind)%nP,amount);
//        cnt++;
//        if((cnt+this->bigBlind)%nP==this->bigBlind) x=0;
//        if(this->Dealer::getNumAct()==1) {
//            cout << "find the winner" << endl;
//            x=0;
//        }
//        
//    }
//    cout << "bettingPrompt3 is Done" << endl;
    
    for(int i=0;i<this->numPlayers;i++){
        int order=(i+this->bigBlind)%this->numPlayers;
        this->players[order].getHands();
//        this->players[order].checkStraight();
//        this->players[order].setFaces();
//        this->players[order].setSuits();
//        this->Dealer::displayPlayersInfo(order);
    }
}


void Dealer::setPlayers(int num){
    this->numPlayers=num;
    this->players=new Hands[this->numPlayers];
    
    for(int i=0;i<this->numPlayers;i++) {
              this->players[i].setPlayerName("player#" + to_string(i));
            }
}

void Dealer::setBlind(){
    this->bigBlind=this->getRound()%(this->getNumPlayers()-1);
    this->smallBlind=this->bigBlind+1;
}


void Dealer::displayPlayersInfo(int num){
    cout << this->Dealer::players[num].getName() << endl;
    if(num==this->Dealer::getBigBlind()) {cout << "BB" << endl;}
    else if (num==this->Dealer::getSmallBlind()) {cout << "SB" << endl;}
    cout << "Balance: $" <<this->Dealer::players[num].getBalance() << endl << endl;
    for(auto& it:this->players[num].getMyCards()){
        it.toString();
    }
    cout << endl;
}

void Dealer::DeckOfCards() {
    for(int i=0;i<52;i++){
        this->deck[i]=new Card(i);
        //cards[i]->toString();
    }
}



void Dealer::shuffle(){
    // Initialize seed randomly 
    srand(time(0)); 
  
    for (int i=0; i<52 ;i++) 
    { 
        // Random for remaining positions. 
        int r = i + (rand() % (52 -i)); 
  
        swap(this->deck[i], this->deck[r]);
    }
    
}

void Dealer::preflop(){
    int nCards=2;
    int order;
    int nP=this->numPlayers;
    int bB=this->bigBlind;
    for(int i=0;i<nCards;i++){
        for(int j=0;j<nP;j++){
            order=(j+bB)%nP;
            this->players[order].addMyCards(*this->deck[j+nP*i]);
            
//            this->deck[j+i+nP*i]->toString();
//            this->Dealer::displayPlayersInfo(order);
            
        }
    }
}

void Dealer::flop(){
    int nCards=3;
    int nP=this->numPlayers;
    int bB=this->bigBlind;
    for(int i=nP*2+1;i<nP*2+1+nCards;i++){
        this->deck[i]->toString();
        for(int j=0;j<nP;j++){
            int order=(j+bB)%nP;
            this->players[order].addMyCards(*this->deck[i]);
        }
    }
}

void Dealer::turn(){
    int nCards=1;
    int nP=this->numPlayers;
    int bB=this->bigBlind;
    for(int i=nP*2+1+3+1;i<nP*2+1+3+1+nCards;i++){
        this->deck[i]->toString();
        for(int j=0;j<nP;j++){
            int order=(j+bB)%nP;
            this->players[order].addMyCards(*this->deck[i]);
        }
    }
}

void Dealer::river(){
    int nCards=1;
    int nP=this->numPlayers;
    int bB=this->bigBlind;
    for(int i=nP*2+1+3+1+1+1;i<nP*2+1+3+1+1+1+nCards;i++){
        this->deck[i]->toString();
        for(int j=0;j<nP;j++){
            int order=(j+bB)%nP;
            this->players[order].addMyCards(*this->deck[i]);
        }
    }
}

int Dealer::bettingPrompt1(){
    int input;
    int raise;
    int diff;
    int nP=this->numPlayers;
    int amount;
    this->players[bigBlind].bet(this->initialContributeAmount);
    this->potAmount+=this->initialContributeAmount;
    cout << "Player" << this->bigBlind << ": $" << this->initialContributeAmount <<" into the Pot"<<endl;
    cout << "Pot: $" << this->getPotAmount() << endl;
    amount=this->players[bigBlind].putInThePot();
    
    this->players[smallBlind].bet(this->initialContributeAmount/2);
    this->potAmount+=this->initialContributeAmount/2;
    diff=amount-this->initialContributeAmount/2;
    
    
    cout << "Player" << this->smallBlind << ": $" << this->initialContributeAmount/2<<" into the Pot" <<endl;
    cout << "Pot: $" << this->getPotAmount() << endl;
    
    
    do{
    cout << "To call you have to put $" << diff << endl;
    cout << "Player" << this->smallBlind <<": Call - 1, Raise - 2, Fold -3" << endl;
    cin >> input;
    if(input==1) {
            this->players[smallBlind].bet(diff);
            this->potAmount+=diff;
            cout << "Player#" << smallBlind << ": $" << diff << endl; 
            cout << "Pot: $" << this->getPotAmount() << endl;

        }
        else if(input==2){
            cout << "Amount: " ;
            do{
                cin >> raise;
                if(raise<=diff) cout << "Amount should be greater than call Amount\n";
            }while(raise<=diff);
            this->players[smallBlind].bet(raise+diff);
            this->potAmount+=(raise+diff);
            cout << "Player#" << smallBlind << ": $" << raise+diff <<" into the Pot" << endl;
            cout << "Pot: $" << this->getPotAmount() << endl;
            amount = this->players[smallBlind].putInThePot();
        }
        else if(input==3){
            this->players[smallBlind].setPlayerInact();
            cout << "Player#" << smallBlind << ": folded" << endl;
            cout << "Pot: $" << this->getPotAmount() << endl;
        }
        else {cout << "wrong input" << endl;}
    }while(input<1||input>3);
    
    return amount;
}

int Dealer::bettingPrompt2(int num, int amount){
    int input;
    do{
        if(this->players[num].getActStatus()){
            int nP=this->numPlayers;
            
            int raise;
            int diff=amount - this->players[num].putInThePot();
            cout << "To call you have to put $" << diff << endl;
            cout << "Player" << num <<": call - 1, Raise - 2, Fold -3" << endl;
            cin >> input;
            if(input==1) {
                this->players[num].bet(diff);
                this->potAmount+=(diff);
                cout << "Player#" << num << ": $" << diff << endl; 
                cout << "Pot: $" << this->getPotAmount() << endl;
            }
            else if(input==2){
                cout << "Amount: " ;
                do{
                    cin >> raise;
                    if(raise<=diff) cout << "Amount should be greater than call Amount\n";
                }while(raise<=diff);

                this->players[num].bet(raise+diff);
                this->potAmount+=(raise+diff);
                cout << "Player#" << num << ": $" << raise+diff << endl; 
                cout << "Pot: $" << this->getPotAmount() << endl;
                amount=this->players[num].putInThePot();
            }
            else if(input==3){
                this->players[num].setPlayerInact();
                cout << "Player#" << num << ": folded" << endl;
                cout << "Pot: $" << this->getPotAmount() << endl;
            }
            else {cout << "wrong input" << endl;}
        }
    }while(input<1||input>3);
    
    return amount;
}

int Dealer::bettingPrompt3(int num, int amount){
    int nP=this->numPlayers;
    int input;
    do{
        if(this->players[num].getActStatus()){
            int raise;
            int diff=amount - this->players[num].putInThePot();
            if(!diff){
                cout << "You can check" << endl;
                cout << "Player" << num <<": check - 1, Raise - 2, Fold -3" << endl;
            
            }
            else{
                cout << "To call you have to put $" << diff << endl;
                cout << "Player" << num <<": call - 1, Raise - 2, Fold -3" << endl;
            
            }
            
            cin >> input;
            if(input==1) {
                
                this->players[num].bet(diff);
                this->potAmount+=(diff);
                cout << "Player#" << num << ": $" << diff << endl; 
                cout << "Pot: $" << this->getPotAmount() << endl;
            }
            else if(input==2){
                cout << "Amount: " ;
                do{
                    cin >> raise;
                    if(raise<=diff) cout << "Amount should be greater than call Amount\n";
                }while(raise<=diff);

                this->players[num].bet(raise+diff);
                this->potAmount+=(raise+diff);
                cout << "Player#" << num << ": $" << raise+diff << endl; 
                cout << "Pot: $" << this->getPotAmount() << endl;
                amount=this->players[num].putInThePot();
            }
            else if(input==3){
                this->players[num].setPlayerInact();
                cout << "Player#" << num << ": folded" << endl;
                cout << "Pot: $" << this->getPotAmount() << endl;
            }
            else {cout << "wrong input" << endl;}
        }
    }while(input<1||input>3);
    
    return amount;
}

int Dealer::getNumAct(){
    int num=0;
    for(int i=0;i<this->numPlayers;i++){
        if(this->players[i].getActStatus()) num++; 
    }
    
    return num;
}