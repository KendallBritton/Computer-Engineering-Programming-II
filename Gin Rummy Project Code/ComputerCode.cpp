//Defintions for ComputerCode header file

#include "ComputerCode.h"

int ComputerCode::DeckToPickFrom(const CardClass& DeckCards) const{
    int i = 0;
    while(i < GetPlayerHandSize() - 1){
        int value1 = ConvertRank(PlayerHand[i]);
        int value2 = ConvertRank(PlayerHand[i + 1]);

        if(value1 == value2){
            for(int j = 0; j < DeckCards.GetPileSize(); j++){
                int compareValue = ConvertRank(DeckCards.GetPileCard(j));

                if(value1 == compareValue){
                    return j;
                }
            }
        }
        i++;
    }
    return -1;
}

int ComputerCode::CardToDiscard() const {
    int compHandSize = GetPlayerHandSize();
    srand(time(NULL));
    int cardToDiscard = rand() % compHandSize;
    return cardToDiscard;
}

void ComputerCode::DisplayMeldedCards() const {
    cout << PlayerName << "'s melded cards: " << endl;
    for(int i = 0; i < MeldedCards.size(); i++){
        cout << PlayerHand[i] << " ";
    }
    cout << endl << endl;
}

vector<int> ComputerCode::SecondTimeMeld() const {
    vector<int> cardsCompWillMeld;

    int i = 0;
    while(i < PlayerHand.size() - 2){ //Converts card ranks to an integer value
        int value1 = ConvertRank(PlayerHand[i]);
        int value2 = ConvertRank(PlayerHand[i + 1]);
        int value3 = ConvertRank(PlayerHand[i + 2]);

        if((value1 == value2) && (value1 == value3)){ //Checks to see if all cards have the same rank
            cardsCompWillMeld.push_back(i + 2);
            cardsCompWillMeld.push_back(i + 1);
            cardsCompWillMeld.push_back(i);

            i = PlayerHand.size() - 2;
        } else {
            i++;
        }
    }

    if(cardsCompWillMeld.size() == 0){ //Check to see if you can meld cards with same suit and increasing order
        int j = 0;
        while(j < PlayerHand.size() - 2){ //Convert the card's rank to an interger value
            int value1 = ConvertRank(PlayerHand[j]);
            int value2 = ConvertRank(PlayerHand[j + 1]);
            int value3 = ConvertRank(PlayerHand[j + 2]);

            if((value3 == value2 + 1) && (value2 == value1 + 1)){ //Check if cards are in increasing values or consecutive order
                string cardSuit1 = RetrieveCardSuit(PlayerHand[j]);
                string cardSuit2 = RetrieveCardSuit(PlayerHand[j + 1]);
                string cardSuit3 = RetrieveCardSuit(PlayerHand[j + 2]);

                if((cardSuit1 == cardSuit2) && (cardSuit2 == cardSuit3)){ //Checks if all cards are the same suit
                    cardsCompWillMeld.push_back(j + 2);
                    cardsCompWillMeld.push_back(j + 1);
                    cardsCompWillMeld.push_back(j);
                    j = PlayerHand.size() - 2;
                } else {
                    j++;
                }
            } else {
                j++;
            }
        }
    }
    return cardsCompWillMeld;
}

void ComputerCode::GamePlay(CardClass& DeckCards){
    cout << PlayerName << "'s turn!" << endl;
    OrganizeHand();

    int PlayerChoice = DeckToPickFrom(DeckCards); // Choose cards to pick up

    if(PlayerChoice != -1){ //Picking up from pick up pile
        InsertFromPickPile(DeckCards,PlayerChoice);
        OrganizeHand();
        PopulateMeldedCards(SecondTimeMeld()); //Populates the computer's meld
    } else {
        InsertIntoPlayerHand(DeckCards.TopDeckCard()); //Picking up from the top of deck
        DeckCards.SelectDeckCard();
    }
    OrganizeHand();

    if(GetPlayerHandSize() > 0){
        DiscardCard(DeckCards,CardToDiscard()); //Computer discards a card
    }
    cout << endl;
}

int ComputerCode::ConvertRank(const string& index) const {
    string RankOfCard = index.substr(0,index.find('-')); //Retrieves the card rank of card index
    int value = atoi(RankOfCard.c_str()); //Converts the Rank into an integer value
    return value; //Return int value
}

string ComputerCode::RetrieveCardSuit(const string& index) const {
    string suit = index.substr(index.find('-') + 1,index.size() - (index.find('-') + 1)); //Gets a substring from after the '-' until the end of the string, which is the rank
    return suit;
}