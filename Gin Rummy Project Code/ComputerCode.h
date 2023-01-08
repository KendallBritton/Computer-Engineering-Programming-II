//Header file for computer code

#ifndef ComputerCode_H
#define ComputerCode_H

#include <iostream>
#include "PlayerCode.h"
#include <ctime>

using namespace std;

class ComputerCode: public PlayerCode { //Computer is a subclass of the PlayerCode class
    public:
        ComputerCode(string name, int Score = 0) : PlayerCode(name,Score){ //constructor calls base class
            PlayerName = name;
            Score = Score;
        }

        virtual int DeckToPickFrom(const CardClass& deck) const; //Override computer gameplay decisions

        virtual int CardToDiscard() const; //Override to output a random card

        virtual void DisplayMeldedCards() const; //Override to display computer's meld and show their name

        virtual vector<int> SecondTimeMeld() const; 

        void GamePlay(CardClass& deck); //Override because the computer has a different algorithm

        int ConvertRank(const string& index) const; //Make cards integer values

        string RetrieveCardSuit(const string& index) const; //Obtains the card suit of an individual card at a given index
};




#endif