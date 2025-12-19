#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(int id, string username)
    : id(id), username(username), cards(nullptr), cardCount(0){

}
Player::Player(){
    cards = nullptr;
}

Player::~Player(){
        delete[] cards;
        cards = nullptr;
}

Player& Player::operator=(const Player& other){
    if (this != &other) {
        id = other.id;
        username = other.username;
        cardCount = other.cardCount;
        delete[] cards;
        cards = nullptr;
        if (cardCount > 0 && other.cards != nullptr){
            cards = new string[cardCount];
            for (int i = 0; i < cardCount; i++){
               cards[i] = other.cards[i];  
            } 
        }
        else{
            cards = nullptr;
        }
    }
    return *this;
}

void Player::drawCard(const string& card){
    if (cards == nullptr){
        cards = new string[1];
        cards[0] = card;
    }
    else{
        string* temp = new string[cardCount+1] ;
        for (int i = 0; i < cardCount; i++){
            temp[i] = cards[i];
        }
        temp[cardCount] = card ;
        delete[] cards;
        cards = temp;
        temp = nullptr ;
    }
    cardCount++ ;
}

void Player::removeCard(int index){
    if(cardCount == 1){
        delete[] cards;
        cards = nullptr;
    }
    string* temp = new string[cardCount-1] ;
    for (int i = 0; i < index; i++){
        temp[i] = cards[i];
    }
    for (int i = index; i < cardCount-1; i++){
        temp[i] = cards[i+1];
    }
    delete[] cards;
    cards = temp;
    temp = nullptr;
    cardCount--;
}

int Player::cardIndex(const string& card){
    for(int i = 0; i < cardCount; i++){
        if (cards[i] == card){
            return i;
        }
    }
    return -1;
}

string Player::getUsername(){
    return username;
}
void Player::setUsername(string username){
    this->username = username;
}
int Player::getId(){
    return id;
}
void Player::setId(int id){
    this->id = id;
}
string* Player::getCards(){
    return cards;
}
void Player::setCards(string* cards){
    this->cards = cards; 
}
int Player::getCardCount(){
    return cardCount;
}
void Player::setCardCount(int count){
    this->cardCount = count;
}