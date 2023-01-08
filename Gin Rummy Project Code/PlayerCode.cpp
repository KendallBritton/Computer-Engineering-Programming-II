//Class defintions for PlayerCode header file

#include "PlayerCode.h"

PlayerCode::PlayerCode(string name, int score) {
    PlayerName = name;
    Score = score;
}

string PlayerCode::GetPlayerName() const {
    return PlayerName;
}

int PlayerCode::GetScore() const {
    return Score;
}

int PlayerCode::GetPlayerHandSize() const {
    return PlayerHand.size();
}

void PlayerCode::CalculateScore() {
    for(int i = 0; i < MeldedCards.size(); i++){
        string RankOfCards = MeldedCards[i].substr(0,MeldedCards[i].find('-'));
        int value = atoi(RankOfCards.c_str());

        if(value < 10){
            Score += 5;
        } else if((value >= 10)&&(value <= 13)){
            Score += 10;
        } else{
            Score += 15;
        }
    }

    for(int i = 0; i < PlayerHand.size(); i++){
        string RankOfCards = PlayerHand[i].substr(0,PlayerHand[i].find('-'));
        int value = atoi(RankOfCards.c_str());

        if(value < 10){
            Score -= 5;
        } else if((value >= 10)&&(value <= 13)){
            Score -= 10;
        } else{
            Score -= 15;
        }
    }
}

string PlayerCode::GetPlayerHandValue(const int& number) const {
    return PlayerHand[number];
}

void PlayerCode::InsertIntoPlayerHand(const string& card) {
    PlayerHand.push_back(card);
}

void PlayerCode::Display() const {
    cout << "Player Hand:" << endl;
    for(int i = 0; i < PlayerHand.size();i++){
        cout << PlayerHand[i] << " ";
    }
    cout << endl;
}

int PlayerCode::DeckToPickFrom(const CardClass& deck) const {
    string PlayerChoice;
    cout << "Do you choose to pick from the pick up pile?" << endl;
    cin >> PlayerChoice;

    if((PlayerChoice == "yes")||(PlayerChoice == "Yes")){
        int LocationFromDeck;
        
        cout << "What is the card location you want to pick from the deck? ";
        cin >> LocationFromDeck;

        while((LocationFromDeck < 0)||(LocationFromDeck >= deck.GetPileSize())){
            cout << "Location not present. Enter another location: ";
            cin >> LocationFromDeck;
        }
        
        return LocationFromDeck;
    } else {
        return -1; 
    }
}

int PlayerCode::CardToDiscard() const {
    int cardToDiscard;

    cout << "Which card do you want to discard? ";
    cin >> cardToDiscard;

    while((cardToDiscard < 0)||(cardToDiscard >= GetPlayerHandSize())){
        cout << "That is an invalid card location. Try again! ";
        cin >> cardToDiscard;
    }
    return cardToDiscard;
}

void PlayerCode::OrganizeHand() {
    sort(PlayerHand.begin(),PlayerHand.end());
}

string PlayerCode::ReturnCard(const int& number) const {
    return PlayerHand[number];
}

void PlayerCode::PopCard(const int& number) {
    PlayerHand.erase(PlayerHand.begin() + number);
}

void PlayerCode::DisplayMeldedCards() const {
    cout << "Player's melded cards: " << endl;
    for(int i = 0; i < MeldedCards.size();i++){
        cout << MeldedCards[i];
        if(i < MeldedCards.size() - 1){
            cout << " ";
        }
    }
    cout << endl << endl;
}

void PlayerCode::PopulateMeldedCards(const vector<int>& CardsToMeld) {
    for(int i = 0; i < CardsToMeld.size(); i++){
        int s = CardsToMeld[i];
        string card = ReturnCard(s);
        MeldedCards.push_back(card);
        PopCard(s);
    }
}

vector<int> PlayerCode::SecondTimeMeld() const {
    string PlayerAnswer;
    cout << "\nDo you want to meld cards? ";
    cin >> PlayerAnswer;

    vector<int> cardsToMeld;

    if((PlayerAnswer == "yes")||(PlayerAnswer == "Yes")){
        cardsToMeld = RetrieveMeldSpots();
    }
    return cardsToMeld;
}

void PlayerCode::ClearHandAndMeld() {
    PlayerHand.clear();
    MeldedCards.clear();
}

vector<int> PlayerCode::CardsToMeld() const {
    vector<int> cardsIWillMeld;
    cout << endl;
    Display();
    cardsIWillMeld = RetrieveMeldSpots();
    return cardsIWillMeld;
}

void PlayerCode::Gameplay(CardClass& DeckCards, const vector<string>& compMeldedCards, const string& compName) {
    cout << "Player's turn!" << endl << endl;

    cout << "Current pick up pile:" << endl; 
    DeckCards.ShowAvailableCards(); //Shows the player their cards

    OrganizeHand();
    Display();
    cout << endl;
    DisplayMeldedCards(); //Shows the player the melded cards

    cout << compName << "'s melded cards: " << endl;
    for(int i = 0; i < compMeldedCards.size(); i++){
        cout << compMeldedCards[i] << " ";
    }
    cout << endl << endl;

    int PlayerChoice = DeckToPickFrom(DeckCards); //Choose card to pick up
    if(PlayerChoice != -1){
        InsertFromPickPile(DeckCards,PlayerChoice);
        OrganizeHand();
        PopulateMeldedCards(CardsToMeld()); //Populates the players melded cards
        cout << endl;
        DisplayMeldedCards();
    } else {
        InsertIntoPlayerHand(DeckCards.TopDeckCard());
        DeckCards.SelectDeckCard();

        if(GetPlayerHandSize() > 0){ //Ask to meld if they didn't want to the first time
            cout << endl;
            OrganizeHand();
            Display();
            PopulateMeldedCards(SecondTimeMeld());
        }
    }
    
    cout << endl;

    if(GetPlayerHandSize() > 0){ //Discards a card
        OrganizeHand();
        Display();
        cout << endl;
        DiscardCard(DeckCards,CardToDiscard());
    }

    cout << endl;

}

void PlayerCode::InsertFromPickPile(CardClass& DeckCards, const int& PlayerChoice) {
    int i = PlayerChoice;
    InsertIntoPlayerHand(DeckCards.GetPileCard(i)); //Puts card into hand
    DeckCards.SelectPileCard(PlayerChoice); //Removes card from pick stack
    
}

void PlayerCode::DiscardCard(CardClass& DeckCards, const int& PlayerChoice) {
    DeckCards.InsertPileCard(ReturnCard(PlayerChoice)); //Insert the card into pick pile
    PopCard(PlayerChoice); //Remove card from stack
}

vector<string> PlayerCode::ReturnVectorOfMeldedCards() const {
    return MeldedCards;
}

vector<int> PlayerCode::RetrieveMeldSpots() const {
    vector<int> CardsToMeld;
    int placement = 0;

    cout << endl;
    cout << "What card from your hand do you want to meld?" << endl;

    while(placement != -1){
        cin >> placement;
        if(placement != -1){
            CardsToMeld.push_back(placement);
        }
    }
    return CardsToMeld;
}
