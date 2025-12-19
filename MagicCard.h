#ifndef MAGICCARD_H
#define MAGICCARD_H
#include "Player.h"
#include <string>
using namespace std;

class MagicCard {

private:
    Player* players;
    string* drawPile;
    string* discardPile;
    int playerCount;
    int drawPileCount ;
    int discardCount;

public:
    MagicCard();
    ~MagicCard();

    void addPlayer(const int playerID, const string name);
    void removePlayer(const int playerID);
    void printPlayers() const;

    void setDrawPile(const string drawPile[], const int size);
    void drawCardFromDeck(const int playerID, const int n);
    void switchHands(const int player1ID, const int player2ID);
    void listDrawPile() const;
    void listDiscardPile() const;
    void listCardsOfPlayer(const int playerID) const;
    void addToDiscard(const string card);
    void play(const int playerID, const string card);
};

#endif 