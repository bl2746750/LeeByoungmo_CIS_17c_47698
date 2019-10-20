/* 
 * File:   Player.cpp
 * Author: Byoung Mo Lee
 * Created on May 27, 2019 10:12 AM
 * Purpose: Player class for Texas Holdem
 * 
 */
#include <list>
#include "Player.h"

Player::Player(){
    this->setPlayerBal();
    this->Player::setPlayerAct();
    this->Player::setInThePot();
}

void Player::addMyCards(Card card){
        this->myCards.push_back(card);
    }