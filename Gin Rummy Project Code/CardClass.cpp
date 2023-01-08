#include "CardClass.h"

void CardClass::AssignDeck(){
    for(int rank = 2; rank < 15; rank++){
        for(int suits = 0; suits < 4; suits++){
            string individualCard;
            int RankOfCard = rank;
            switch(RankOfCard){
                case(2):
                    individualCard += "2\0";
                    break;
                case(3):
                    individualCard += "3\0";
                    break;
                case(4):
                    individualCard += "4\0";
                    break;
                case(5):
                    individualCard += "5\0";
                    break;
                case(6):
                    individualCard += "6\0";
                    break;
                case(7):
                    individualCard += "7\0";
                    break;
                case(8):
                    individualCard += "8\0";
                    break;
                case(9):
                    individualCard += "9\0";
                    break;
                case(10):
                    individualCard += "10\0";
                    break;
                case(11):
                    individualCard += "11\0";
                    break;
                case(12):
                    individualCard += "12\0";
                    break;
                case(13):
                    individualCard += "13\0";
                    break;
                case(14):
                    individualCard += "14\0";
                    break;
            }
            int SuitOfCard = suits;
            switch(SuitOfCard){
                case(0):
                    individualCard.append("-Heart");
                    break;
                case(1):
                    individualCard.append("-Club");
                    break;
                case(2):
                    individualCard.append("-Spade");
                    break;
                case(3):
                    individualCard.append("-Diamond");
                    break;
            }
            DeckCards.push_back(individualCard);
        }
    }
    
}

void CardClass::ShuffleDeck(){
    srand(time(0));
    random_shuffle(DeckCards.begin(),DeckCards.end());
}

void CardClass::ShowAvailableCards() const{
    for(int i = 0; i < PileCards.size(); i++){
        cout << PileCards[i] << " ";
    }
    cout << endl << endl;
}

string CardClass::ReturnCard(const int& number) const{
    return DeckCards[number];
}

void CardClass::SelectDeckCard(){
    DeckCards.pop_back();
}

int CardClass::GetDeckSize() const{
    return DeckCards.size();
}

int CardClass::GetPileSize() const{
    return PileCards.size();
}

void CardClass::UpdatePickPile(){
    int number = DeckCards.size() - 1;
    string copyDeck = DeckCards[number];
    DeckCards.pop_back();
    PileCards.push_back(copyDeck);
}

string CardClass::GetPileCard(const int& number) const{
    return PileCards[number];
}

void CardClass::InsertPileCard(const string& card){
    PileCards.push_back(card);
}

void CardClass::SelectPileCard(int n){
    PileCards.erase(PileCards.begin() + n);
}

string CardClass::TopDeckCard() const{
    return DeckCards[GetDeckSize()-1];
}
