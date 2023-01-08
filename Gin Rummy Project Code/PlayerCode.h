//Player Code header file

#ifndef PlayerCode_H
#define PlayerCode_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "CardClass.h"

using namespace std;

class PlayerCode{
    protected:
        string PlayerName;
        int Score;
        vector<string> MeldedCards;
        vector<string> PlayerHand;
    public:
        PlayerCode(string PlayerName, int Score = 0); // Constructer that gets the player name and score

        virtual string GetPlayerName() const; //Returns the player's name

        virtual int GetScore() const; //Returns the player's score

        virtual int GetPlayerHandSize() const; //Returns the size of the player's hand

        virtual void CalculateScore(); //Calculates the player's score

        virtual string GetPlayerHandValue(const int& number) const; //Returns the value of the hand at a specific number

        virtual void InsertIntoPlayerHand(const string& card); //Inserts card into the hand

        void Display() const; //Displays the player's hand

        virtual int DeckToPickFrom(const CardClass& deck) const; //Determine what deck the player will pick from

        virtual int CardToDiscard() const; //Determines what card the player will discard

        void OrganizeHand(); //Sorts the player's hand

        virtual string ReturnCard(const int& number) const; //Returns the card at this location

        virtual void PopCard(const int& number); //Pops the card at number from the hand

        virtual void DisplayMeldedCards() const; //Displays the melded cards

        virtual void PopulateMeldedCards(const vector<int>& CardsToMeld); //Populates the melded cards

        virtual vector<int> SecondTimeMeld() const; //To meld the player's card

        virtual void ClearHandAndMeld(); //Resets the cards to 0 after each hand

        vector<int> CardsToMeld() const; //Populates a vector of the melded cards from their hand

        virtual void Gameplay(CardClass& DeckCards, const vector<string>& compMeldedCards, const string& compName); //Main gameplay, iterates through every turn

        virtual void InsertFromPickPile(CardClass& DeckCards, const int& PlayerChoice); //Inserts the card from player to end of pick pile

        virtual void DiscardCard(CardClass& DeckCards, const int& PlayerChoice); //Discards the card of player's choice

        virtual vector<string> ReturnVectorOfMeldedCards() const; //Returns a vector of player's melded cards

        vector<int> RetrieveMeldSpots() const; //Returns a vector of card locations that the player wants to meld

};

#endif