#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {

private:
    int id;
    string username;
    string* cards;
    int cardCount;

public:
    Player();
    Player(int id, string username);

    ~Player();

    Player& operator=(const Player& other);

    string getUsername();
    void setUsername(string username);
    int getId();
    void setId(int id);
    string* getCards();
    void setCards(string* cards);
    int getCardCount();
    void setCardCount(int count);

    void drawCard(const string& card);
    void removeCard(int index);
    int cardIndex(const string& card);
};
#endif