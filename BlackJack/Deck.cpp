#include "Deck.h"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int Deck::deckSize() {
    return mydeck.size();
}

void Deck::newDeck() {    
    if(!mydeck.empty()) {
        mydeck.clear();
    }
    
    for(int i = 1; i <= 13; i++) {
        //for aces
        if(i == 1) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Ace", "Hearts", 11);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Ace", "Diamonds", 11);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Ace", "Spades", 11);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Ace", "Clubs", 11);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for twos
        else if(i == 2) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Two", "Hearts", 2);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Two", "Diamonds", 2);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Two", "Spades", 2);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Two", "Clubs", 2);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for threes
        else if(i == 3) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Three", "Hearts", 3);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Three", "Diamonds", 3);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Three", "Spades", 3);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Three", "Clubs", 3);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for fours
        else if(i == 4) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Four", "Hearts", 4);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Four", "Diamonds", 4);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Four", "Spades", 4);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Four", "Clubs", 4);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for fives
        else if(i == 5) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Five", "Hearts", 5);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Five", "Diamonds", 5);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Five", "Spades", 5);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Five", "Clubs", 5);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for sixes
        else if(i == 6) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Six", "Hearts", 6);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Six", "Diamonds", 6);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Six", "Spades", 6);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Six", "Clubs", 6);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for sevens
        else if(i == 7) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Seven", "Hearts", 7);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Seven", "Diamonds", 7);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Seven", "Spades", 7);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Seven", "Clubs", 7);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for eights
        else if(i == 8) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Eight", "Hearts", 8);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Eight", "Diamonds", 8);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Eight", "Spades", 8);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Eight", "Clubs", 8);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for nines
        else if(i == 9) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Nine", "Hearts", 9);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Nine", "Diamonds", 9);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Nine", "Spades", 9);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Nine", "Clubs", 9);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for tens
        else if(i == 10) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Ten", "Hearts", 10);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Ten", "Diamonds", 10);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Ten", "Spades", 10);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Ten", "Clubs", 10);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for Jacks
        else if(i == 11) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Jack", "Hearts", 10);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Jack", "Diamonds", 10);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Jack", "Spades", 10);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Jack", "Clubs", 10);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for queens
        else if(i == 12) {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("Queen", "Hearts", 10);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("Queen", "Diamonds", 10);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("Queen", "Spades", 10);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("Queen", "Clubs", 10);
                    mydeck.push_back(myCard);
                } 
           }  
        }
        //for kings
        else {
           //add different suits
           for(int j = 0; j < 4; j++) {
                //hearts
                if(j == 0) {
                    Card myCard ("King", "Hearts", 10);
                    mydeck.push_back(myCard);
                } 
                //diamonds
                else if(j == 1) {
                    Card myCard ("King", "Diamonds", 10);
                    mydeck.push_back(myCard);
                } 
                //spades
                else if(j == 2) {
                    Card myCard ("King", "Spades", 10);
                    mydeck.push_back(myCard);
                }
                //clubs 
                 else {
                    Card myCard ("King", "Clubs", 10);
                    mydeck.push_back(myCard);
                } 
           }  
        }
    }
}

Card Deck::dealCard() {
     srand((int)time(0));
     Card randCard;
     int randNum = 0;

     randNum = rand() % mydeck.size();

     auto ptr = mydeck.begin();

     ptr += randNum;

     if(!mydeck.empty()) {
         randCard = mydeck.at(randNum);
         mydeck.erase(ptr);
     }

     return randCard;
     
}