// Card Class header file

#ifndef CardClass_H
#define CardClass_H

#include <string>
#include <iostream>
#include <vector> 
#include <ctime>
#include <algorithm>
using namespace std;

class CardClass{
    private:
        vector<string> DeckCards;
        vector<string> PileCards;

    public:
        void AssignDeck();  //Gives the deck values

        void ShuffleDeck(); //Shuffles deck

        void ShowAvailableCards() const; //Shows the cards that can be chosen

        string ReturnCard(const int& number) const; //Returns the card in the deck at a specific number

        void SelectDeckCard(); //Selects and grabs a card from the back of the deck

        int GetDeckSize() const; //Returns the size of deck

        int GetPileSize() const; //Returns the size of the pick up pile

        void UpdatePickPile(); //Updates the pick up pile

        string GetPileCard(const int& number) const; //Returns the card from pick up pile at specific number

        void InsertPileCard(const string& card); //Puts card at the end of the pick up pile (on top of pile)

        void SelectPileCard(int n); //Selects and grabs a card off the back of pick up pile

        string TopDeckCard() const; //Gives the top card on deck

};
#endif