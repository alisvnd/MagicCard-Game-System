#include "MagicCard.h"
#include <iostream>
#include <string>
using namespace std; 

MagicCard::MagicCard()
    : players(nullptr), drawPile(nullptr), discardPile(nullptr), playerCount(0), drawPileCount(0), discardCount(0){
};
MagicCard::~MagicCard(){
    delete[] players;
    delete[] drawPile;
    delete[] discardPile;
}

void MagicCard::addPlayer(const int playerID, const string name){ // adds them in the correct place so that the IDs are in ascending order
    if (players == nullptr){
        players = new Player[1] ;
        playerCount++;
        players[0] = Player(playerID, name);
        cout<< "Added player " << name << " with ID " << playerID << "." << endl ;
    }
    else{
        bool existing = false;
        int index = playerCount;
        for (int i=0; i < playerCount; i++){
            if (players[i].getId() > playerID){
                index = i;
            }
            else if(players[i].getId() == playerID){
                cout<< "Cannot add player. ID "<< playerID << " already exists." << endl;
                existing = true;
                break;
            }
        }
        if (!existing){
            Player* temp = new Player[playerCount + 1];
            for (int i=0; i < index; i++){
                temp[i] = players[i];
            }
            temp [index] = Player(playerID, name);
            for (int i = index; i < playerCount; i++){
                temp[i+1] = players[i];
            }
            cout<< "Added player " << name << " with ID " << playerID << "." << endl ;
            delete[] players;
            players = temp;
            playerCount++;
            temp = nullptr;
        }
    }
}
void MagicCard::removePlayer(const int playerID){
    bool existing = false;
        for (int i=0; i < playerCount; i++){
            if (players[i].getId() == playerID){
                cout<< "Removed player "<< playerID << "." << endl;
                existing = true;
                Player* temp = new Player[playerCount - 1];
                for (int k=0; k < i; k++){
                    temp[k] = players[k];
                }
                for (int k=i; k < playerCount-1; k++){
                    temp[k] = players[k+1];
                }
                delete[] players;
                players = temp;
                playerCount--;
                temp = nullptr;
                break;
            }
        }
        if (!existing){
            cout<< "Cannot remove player. There is no player with ID " << playerID << "." << endl;
        }

}

void MagicCard::printPlayers() const{
    if (playerCount == 0 || players == nullptr){
        cout<< "Cannot print players. There is no player in the game." << endl ;
    }
    else{
        cout << "Players :" << endl ;
        for (int i = 0; i < playerCount; i++){
            cout<< "Player "<< players[i].getId() << " : " << players[i].getUsername() << endl ;
        }
    }
}

void MagicCard::setDrawPile(const string drawPile[], const int size){
    if (this->drawPile == nullptr){
        this->drawPile = new string[size] ;
        drawPileCount = size ;
        for (int i = 0; i < size; i++){
            this->drawPile[i] = drawPile[i];
        }
        cout << "Draw pile has been initialized." << endl;
    }
}

void MagicCard::drawCardFromDeck(const int playerID, const int n){
    if (drawPileCount == 0){
        return;
    }
    if (n >= drawPileCount || n < 0 || drawPile == nullptr){
        cout << "Cannot draw card. The input index is not valid." << endl ;
    }
    else{
        bool exists = false ;
        for (int i = 0; i < playerCount; i++){
            if (players[i].getId() == playerID){
                exists = true;
                players[i].drawCard(drawPile[n]) ;
                if (discardCount == 0){
                cout<< players[i].getUsername() << " drew card " << drawPile[n] << " from the draw pile." << endl ;
                }
                break;
            }
        }
        if (exists){
            string* temp = new string[drawPileCount - 1];
            for (int k=0; k < n; k++){
                temp[k] = drawPile[k];
            }
            for (int k=n; k < drawPileCount-1; k++){
                temp[k] = drawPile[k+1];
            }
            delete[] drawPile;
            drawPile = temp;
            drawPileCount--;
            temp = nullptr;
        }
    }
}
void MagicCard::switchHands(const int player1ID, const int player2ID){
    Player* p1 = nullptr;
    Player* p2 = nullptr;
    for (int i = 0; i < playerCount; i++){
        if (players[i].getId() == player1ID){
            p1 = &players[i];
        }
        if (players[i].getId() == player2ID){
            p2 = &players[i];
        }
    }
    if (p1 == nullptr || p2 == nullptr){
        cout << "Cannot switch hands. One or both players do not exist." << endl;
    }
    else{
        string* temp = p1->getCards();
        int tempCount = p1->getCardCount();
        p1->setCards(p2->getCards());
        p1->setCardCount(p2->getCardCount());
        p2->setCards(temp);
        p2->setCardCount(tempCount);
        cout << "Switched hands between " << p1->getUsername()<<" and "<< p2->getUsername()<<"."<<endl;
    }
}
void MagicCard::listDrawPile() const{
    if (drawPileCount == 0 || drawPile == nullptr){
        cout << "Draw pile is empty." << endl;
    }
    else{
        cout << "Draw pile: [" ;
        for (int i = 0; i < drawPileCount; i++){
            if (i != 0){
                cout<< ", ";
            }
            cout<< drawPile[i] ;
        }
        cout<<"]"<<endl;
    }
}
void MagicCard::listDiscardPile() const{
    if (discardCount == 0 || discardPile == nullptr){
        cout << "Discard pile is empty." << endl ;
    }
    else{
        cout << "Discard pile: [" ;
        for (int i = 0; i < discardCount; i++){
            if (i != 0){
                cout<< ", ";
            }
            cout<< discardPile[i] ;
        }
        cout<<"]"<<endl;
    }
}

void MagicCard::listCardsOfPlayer(const int playerID) const{
    bool exists = false;
    for (int i = 0; i < playerCount; i++){
        if (players[i].getId() == playerID){
            exists = true;
            cout<<"Cards of "<< players[i].getUsername()<< ": [" ;
            for(int k = 0; k < players[i].getCardCount(); k++){
                if (k != 0){
                    cout<< ", ";
                }
                cout<< players[i].getCards()[k];
            }
            cout << "]"<<endl;
            break;
        }
    }
    if (!exists){
        cout << "Cannot list cards. Player with ID " << playerID << " does not exist." << endl;
    }
}

void MagicCard::addToDiscard(const string card){
    if (discardPile == nullptr){
        discardPile = new string[1];
        discardPile[0] = card;
    }
    else{
        string* temp = new string[discardCount+1];
        for (int i = 0; i < discardCount; i++){
            temp[i] = discardPile[i];
        }
        temp[discardCount] = card ;
        delete[] discardPile;
        discardPile = temp;
        temp = nullptr;
    }
    discardCount++;
}

void MagicCard::play(const int playerID, const string card){//player var mı, varsa bu kart var mı onda, sonra attı discarda ekle kendinden çıkar son kartla uyuşmuyosa draw yap kartı biten kazansın
bool exists = false;
    for (int i = 0; i < playerCount; i++){
        if (players[i].getId() == playerID){
            exists = true;
            Player& p = players[i];
            int index = p.cardIndex(card);
            if (index == -1){
                cout << "The player does not have "<< card <<" card."<< endl;
            }
            else{
                p.removeCard(index);
                cout<<"Player " << playerID <<" played " << card ;
                string s ;
                if (discardPile == nullptr){
                    s = card;
                }
                else {
                    s = discardPile[discardCount-1];
                }
                if (s[0] == card[0] || s.substr(1) == card.substr(1)){
                    cout<<"."<<endl;
                    if (p.getCardCount() == 0){
                        cout<<"The game has ended. Player " << playerID << " won."<< endl ;
                    }
                }
                else{
                    drawCardFromDeck(playerID, 0);
                    cout<< " then drew " << p.getCards()[p.getCardCount()-1] << "." << endl;
                    if (drawPileCount == 0){
                        cout<<"The game has ended. No cards remain in the draw pile." << endl;
                    }
                }
                addToDiscard(card);
            }
            break;
        }
    }
    if(!exists){
        cout << "There is no player with ID " << playerID << "." << endl;
    }
}