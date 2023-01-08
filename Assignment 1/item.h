#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
using namespace std;


class Item{
    private:
    double cost;
    string itemDescription;
    public:
    Item(string itemName, double itemCost):itemDescription{itemName}, cost{itemCost} {}
    Item():itemDescription{NULL}, cost{NULL} {}
    void setCost(double cost);
    void setDescription(string itemDescription);
    double getCost();
    string getDescription();
    friend ostream& operator<<(ostream& os, Item& it);
};

#endif