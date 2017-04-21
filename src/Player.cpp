//
//  Player.cpp
//  varianet_server
//
//  Created by cemcakmak on 10/04/15.
//
//

#include "Player.h"

void Player::setup(){
    
    life = 100;
    
    
}

bool Player::isConnected() const{
    
    return connected;
    
}

void Player::setConnection(bool connection){
    
    connected = connection;
    
}

string Player::getIP() const{
    
    return IP;
    
}

void Player::setIP(string newIP) {
    
    IP = newIP;
    
}

ofColor Player::getColor() const{
    
    return color;
    
}

void Player::setColor(ofColor newColor){
    
    color.set(newColor);
}

void Player::setColorByIndex(int index){
    // 161,24,87 - purple
    // 219,227,0 - yellow
    // 50,153,187 - blue
    // 3271AD - koyu
    // 103,185,88 - green
    // 2C4E00 koyu
    switch (index) {
        case 1:
            color.setHex(0x0A447B);
//            color.set(161,24,87);
            break;
        case 2:
            color.set(50,153,187);
//            color.setHex(0x2A5E91);
            break;
        case 3:
            color.set(103,185,88);
            break;
        case 4:
            color.set(219,227,0);
            break;
        default:
            break;
    }
    
}

float Player::getLife() const{
    
    return life;
    
}

void Player::setLife(float newLife){
    
    life = newLife;
    
}

void Player::changeLife(float amount){
    
    if(life + amount > 100) life = 100;
    else if(life + amount < 0) life = 0;
    else life += amount;
    
}

int Player::getDiscIndex() const{
    
    return discIndex;
    
}

void Player::setDiscIndex(int index){
    
    discIndex = index;
    
}

string Player::getNick() const{
    
    return nick;
}

void Player::setNick(string nickname){
    
    nick = nickname;
}
