#include <vector>
#include <iostream>
#include "CardClass.h"
#include "ComputerCode.h"
#include "PlayerCode.h"

using namespace std;

void IntroScreen(); //Outputs the intro screen

void OutroScreen(PlayerCode& Player, ComputerCode& Computer); //Output screen that declares winner

void dealDeck(PlayerCode& Player, ComputerCode& Computer, CardClass& DeckCards, int Count); //Deals cards into each hand and removes seleted cards from deck

void OutputScore(PlayerCode& Player, ComputerCode& Computer, int roundCount); //Shows the score of each player after each round

int main(){
    IntroScreen(); //Outputs the intro screen which displays instructions etc.

    string name;

    cout << "\nEnter your name: "; //Retrieve player's name
    getline(cin,name);
    PlayerCode user(name);

    cout << "\nEnter the computer's name: "; //Retrieve computer's name
    getline(cin,name);
    ComputerCode comp(name);
    cout << endl;

    int roundCount = 0;

    while((user.GetScore() < 150) && (comp.GetScore() < 150)){
        
        OutputScore(user,comp,roundCount); //Output Score

        CardClass deck; //Assigns and shuffles the deck
        deck.AssignDeck();
        deck.ShuffleDeck();

        user.ClearHandAndMeld(); //Erase any remaining cards in hand or meld
        comp.ClearHandAndMeld();

        dealDeck(user,comp,deck,roundCount); //Deals the deck to both hands

        int count = roundCount; //Reset count to roundCount, it chooses who goes first

        while((user.GetPlayerHandSize() > 0) && (comp.GetPlayerHandSize() > 0) && (deck.GetDeckSize() > 0)){ //Actually runs the game as long as both players have cards
            if(count % 2 == 0){
                user.Gameplay(deck,comp.ReturnVectorOfMeldedCards(),comp.GetPlayerName());
            } else {
                comp.GamePlay(deck);
            }
            count++;
        }
        roundCount++; //Increases round count when round is over

        int initialPlayerScore = user.GetScore();
        int initialCompScore = comp.GetScore();

        user.CalculateScore(); //Calculates score
        user.CalculateScore();

        cout << "Points score this round: " << endl << user.GetPlayerName() << ": " << user.GetScore() - initialPlayerScore << 
        endl << comp.GetPlayerName() << ": " << comp.GetScore() - initialCompScore << endl << endl;
    }
    OutroScreen(user,comp); //Declares winner
    system("pause");

}

void IntroScreen(){
    cout << "Gin Rummy" << endl 
    << "By Zachary Turnmire, Tim Ocmand, and Kendall Britton" << endl << endl;

    cout << "The goal of Gin Rummy is to achieve 150 points. Points are earned by gathering melds and having little to no deadwood left over in your hand.\n" <<
    "Your score is calculated by the number of melds you have in your hand at the end of a round.  Melds are a set or run of numbers. A set is 3 cards\n" <<
    "of the same value. A run is 3 cards in ascending order that have the same suit. However, King - Ace - Two is not an acceptable run as it wraps around.\n" << 
    "Deadwood is the cards that don't fit into any meld. In Gin Rummy, both players start with 10 cards, and each\n" <<
    "player can choose to draw from the discard pile or facedown deck once each turn. Once a player has drawn a card from either deck, he must discard\n" <<
    "to the discard pile to end his turn.\n\n";

    cout << "Some basic gameplay functions are as followed:\n\n"
         << "1. When asked the question to pick from a certain deck or meld, respond by typing yes or no.\n"
         << "2. When you are selecting a card location to either pick up or meld, remember that the placement is based off integer values starting at 0.\n"
         << "3. When choosing cards to meld, remember that as each number is entered the vector is updated. For example if you want to meld 3 cards that\n"
         << "   are in the vector indices 0,1, and 2, when asked to meld you would enter 0,0,0 because the vector will update in size after each input.\n"
         << "4. Once you are done melding all the cards you want, enter -1 to exit the card melding screen.\n\n";

    cout << "Now you're ready to play!! Enter you name below to begin!\n\n";
}

void OutroScreen(PlayerCode& Player, ComputerCode& Computer){
    cout << "Final Score: " << endl << Player.GetPlayerName() << ": " 
    << Player.GetScore() << endl << Computer.GetPlayerName() << ": " 
    << Computer.GetScore() << endl << endl;

    if(Player.GetScore() >= Computer.GetScore()){
        cout << "Congrats, " << Player.GetPlayerName() << "! You beat the computer.";
    } else{
        cout << "Sorry, " << Computer.GetPlayerName() << " defeated you!";
    }

    cout << endl << "Thanks for playing!\n\n";
}

void dealDeck(PlayerCode& Player, ComputerCode& Computer, CardClass& DeckCards, int Count){
    if(Count % 2 == 0){
        int i = 0;
        while(i < 22){
            Computer.InsertIntoPlayerHand(DeckCards.TopDeckCard());
            DeckCards.SelectDeckCard();
            i++;
            Player.InsertIntoPlayerHand(DeckCards.TopDeckCard());
            DeckCards.SelectDeckCard();
            i++;
        }
        DeckCards.UpdatePickPile();
    }

}

void OutputScore(PlayerCode& Player, ComputerCode& Computer, int roundCount){
    cout << "After " << roundCount << " rounds: " << endl
    << "Your current score: " << Player.GetScore() << endl 
    << Computer.GetPlayerName() << "'s current score: " <<
    Computer.GetScore() << endl;
}

