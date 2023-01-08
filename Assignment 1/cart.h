#ifndef CART_H
#define CART_H

#include "item.h"


class GroceryCart{
    private:
    vector<Item> itemList;
    int itemCount;
    double totalCost;
    bool checkCartEmpty;
    public:
    GroceryCart():itemList(0){}
    void insertItem(Item& it);
    void deleteItem(Item);
    int getItemCount();
    bool isCartEmpty();
    double calcTotalCost();
    friend bool operator==(const GroceryCart& lhs, const GroceryCart& rhs);
};

#endif
