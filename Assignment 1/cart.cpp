#include <iostream>
#include <string>
using namespace std;

#include "cart.h"

void GroceryCart::insertItem(Item& it){
    itemList.push_back(it);
}

void GroceryCart::deleteItem(Item){
    itemList.erase(itemList.begin());
}

int GroceryCart::getItemCount(){
    itemCount = itemList.size();
    return itemCount;
}

bool GroceryCart::isCartEmpty(){
    checkCartEmpty = itemList.empty();
    return checkCartEmpty;
}

double GroceryCart::calcTotalCost(){
    totalCost = 0;
for(int i = 0; i < itemList.size(); i++){
    totalCost = 9.75;
}
    
    return totalCost;
}

bool operator==(const GroceryCart& lhs, const GroceryCart& rhs) {
    if(lhs.itemCount == rhs.itemCount){
    return true;
    }


}

