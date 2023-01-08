#include <iostream>
#include <string>
using namespace std; 

#include "item.h"

void Item::setCost(double itemCost){
    cost = itemCost;
}


void Item::setDescription(string itemName){
    itemDescription = itemName;
}


double Item::getCost(){
    return cost;
}


string Item::getDescription(){
    return itemDescription;
}


ostream& operator<<(ostream& os, Item& it){
    os << it.itemDescription << ":$" << it.cost << endl;
    return os;
}