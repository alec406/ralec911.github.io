#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <iomanip>
#include <ios>

using namespace std;
#include <string>

int main() {
    vector<Card> dealerHand;
    vector<Card> playerHand;
    int playerTotal = 0;
    int dealerTotal = 0;
    Deck myDeck;
    char userChoice = 'y';
    double betAmount = 0.0;
    char hitOrStand = ' ';
    char completeCount = 'n'; //checks if both dealers original cards are included in total
    cout.precision(2); //currency format

    //initialize playerBalance to 2500
    double playerBalance = 2500.0;

    //initialize deck
    myDeck.newDeck();

    //display rules
    cout << "Welcome to BlackJack" << endl;
    cout << "Rules For Game:" << endl;

    cout << "Your score beats dealers's score- 1:1 payout ratio" << endl;
    cout << "Dealer’s score beats your score – 1:1 loss ratio" << endl;
    cout << "Natural Blackjack (A in two. Auto Win unless dealer has a blackjack, then a push) – 3:2 payout ratio." << endl;
    cout << endl;

    while(playerBalance != 0.0 && userChoice == 'y') {

        //reset these variables
        hitOrStand = ' ';
        completeCount = 'n';
        
        //clear previous hands
        playerHand.clear();
        dealerHand.clear();

        //reset totals
        playerTotal = 0.0;
        dealerTotal = 0.0;

        //reshuffle deck if needed
        if(myDeck.deckSize() < 20) {
            myDeck.newDeck();
            cout << "Shuffling" << endl;
        }

    
    //take bet 
        do {
            cout << "Your balance: $" << fixed << playerBalance << endl;
            cout << "Place your bet: " << endl;
            cin >> betAmount;

            if(betAmount == 0.0) {
                cout << "Not a valid bet" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if(betAmount > playerBalance) {
                 cout << "You don't have that many chips" << endl;
            }
            cout << endl;

        }while((betAmount > playerBalance) || betAmount == 0.0);

         //subtract out bet amount from balance
        playerBalance -= betAmount;


        cout << "The Deal" << endl;
        cout << endl;
        
        //deal cards
        myDeck.newDeck();
        for(int i = 0; i < 2; i++) {
            Card playerCard = myDeck.dealCard();
            Card dealerCard = myDeck.dealCard();
        
            playerHand.push_back(playerCard);
            playerTotal += playerCard.getValue();

            dealerHand.push_back(dealerCard);
        }
        dealerTotal += dealerHand.at(0).getValue();

        //print player hand
        cout << "Your hand:" << endl;
        for(int i = 0; i < 2; i++) {
            playerHand.at(i).printCard();
        }
        //sets one ace to 1 if hand contains 2 aces
        if(playerHand.at(0).getValue() == 11 && playerHand.at(1).getValue() == 11) {
           playerHand.at(1).setValue(1);
           playerTotal -= 10;
        }
        cout << "Your Total: " << playerTotal << endl;
        cout << endl;


        //print dealers hand
        cout << "Dealer hand:" << endl;
        dealerHand.at(0).printCard();
        if(dealerHand.at(0).getValue() == 10 || dealerHand.at(0).getValue() == 11) {
            dealerHand.at(1).printCard();
            dealerTotal += dealerHand.at(1).getValue();
            completeCount = 'y';
        }
        //sets one ace to 1 if hand contains 2 aces
        if(dealerHand.at(0).getValue() == 11 && dealerHand.at(1).getValue() == 11) {
           dealerHand.at(1).setValue(1);
           dealerTotal -= 10;
        }
        cout << "Dealer Total: " << dealerTotal << endl;
        cout << endl;

        //check if player has a blackjack
        if((playerHand.at(0).getValue() == 10) && (playerHand.at(1).getValue() == 11) ||        
            (playerHand.at(0).getValue() == 11) && (playerHand.at(1).getValue() == 10)) {
                //check if dealer has blackjack too
                if((dealerHand.at(0).getValue() == 10 && dealerHand.at(1).getValue() == 11) ||        
                    dealerHand.at(0).getValue() == 11 && dealerHand.at(1).getValue() == 10) {
                        cout << "You and the dealer both had blackjacks. Tie" << endl;
                }
                else {
                    cout << "Congratulations you have a blackjack! You win: " << (betAmount * 1.5) << endl;
                    playerBalance += (betAmount + (betAmount * 1.5));
                }
        }
        //check if dealer has a blackjack
        else if((dealerHand.at(0).getValue() == 10 && dealerHand.at(1).getValue() == 11) ||        
                    dealerHand.at(0).getValue() == 11 && dealerHand.at(1).getValue() == 10) {
                        cout << "Dealer has a blackjack" << endl;
                }
        else {
            //would you like to stand or hit(s or h)
            do {
                cout << "Would you like to hit or stand(s or h)" << endl;
                cin >> hitOrStand;

                //checks for valid input
                if(hitOrStand != 'h' && hitOrStand != 's') {
                    cout << "Not valid input. Please enter h or s." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }while(hitOrStand != 'h' && hitOrStand != 's');

            while(hitOrStand == 'h') {
                Card myCard = myDeck.dealCard();

                playerHand.push_back(myCard);
                playerTotal += myCard.getValue();

                cout << "Your hand:" << endl;
                for(int i = 0; i < playerHand.size(); i++) {
                   playerHand.at(i).printCard();
                }
                //check if an ace needs to be changed to 1
                if(playerTotal > 21) {
                   for(int i = 0; i < playerHand.size(); i++) {
                       if(playerTotal > 21 && playerHand.at(i).getValue() == 11) {
                           playerHand.at(i).setValue(1);
                           playerTotal -= 10;
                       }
                   } 
                }
                cout << "Your Total: " << playerTotal << endl;
                cout << "Dealers Total: " << dealerTotal << endl;
                cout << endl;

                if(playerTotal > 21) {
                    cout << "You busted" << endl;
                    hitOrStand = ' ';
                }
                else {
                    //would you like to stand or hit(s or h)
                    cout << "Would you like to hit or stand" << endl;
                    cin >> hitOrStand;
                }
            } 

            //dealers turn if player did not bust 
            if(playerTotal < 22) {
                //adds second card of dealers hand if not included in total already
                if(completeCount != 'y') {
                    dealerTotal += dealerHand.at(1).getValue();
                }
                cout << "Dealers turn: " << endl;
                 while(dealerTotal < 17) {
                    Card myCard = myDeck.dealCard();

                    dealerHand.push_back(myCard);
                    dealerTotal += myCard.getValue();

                     //changes ace to a one if it causes a bust
                    if(dealerTotal > 21) {
                      for(int i = 0; i < dealerHand.size(); i++) {
                           if(dealerTotal > 21 && dealerHand.at(i).getValue() == 11) {
                               dealerHand.at(i).setValue(1);
                               dealerTotal -= 10;
                           }
                      } 
                    }
                }
                for(int i = 0; i < dealerHand.size(); i++) {
                        dealerHand.at(i).printCard();
                }
                
                cout << "Dealers Total: " << dealerTotal << endl;
                cout << endl;
            }

            //check for winner
            cout << "Results" << endl;
            cout << "Dealer Total: " << dealerTotal << "    Your Total: " << playerTotal << endl;
            if((playerTotal < 22 && (playerTotal > dealerTotal)) || (playerTotal < 22 && dealerTotal > 21))  {
                cout << "Congratulations you win: $" << fixed << betAmount << endl;
                playerBalance += betAmount * 2;
            }
            else if(playerTotal < 22 && (playerTotal == dealerTotal)) {
                cout << "Push" << endl;
                playerBalance += betAmount;
            }
            else {
                cout << "You lose" << endl;
            }  
        } 

        if(playerBalance == 0.0) {
            cout << "Sorry you are out chips." << endl;
        }
        else {
            do {
                cout << "Would you like to play another hand?(y or n)" << endl;
                cin >> userChoice; 
                if(userChoice!= 'n' && userChoice != 'y') {
                    cout << "Invalid choice. Please enter y or n." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }while(userChoice != 'y' && userChoice!= 'n');
        }  
    }
    
    return 0;
}

