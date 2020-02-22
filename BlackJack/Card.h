#include <string>
using namespace std;

#ifndef CARD_H
#define CARD_H


class Card {
    public:
       void setName(string cardName);
       void setSuit(string cardSuit);
       void setValue(int cardValue);
       string getName();
       string getSuit();
       int getValue();
       void printCard();
       Card();
       Card(string cardName, string cardSuit, int cardValue);
    private:
       string name;
       string suit;
       int value;
    
};

#endif