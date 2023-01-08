#include <iostream>
#include "item.h" // You need to code this
#include "cart.h" // You need to code this

using namespace std;

int main()
{
    Item it1{"Salad", 5.50}, it2{"Milk", 2.50}, it3{"Bread", 1.75}, it4; //Tests the Item constructors
    
   
    GroceryCart cart1; // Test GroceryCart constructor

    cart1.insertItem(it1);
    cart1.insertItem(it2);
    cart1.insertItem(it3);

    if (!cart1.isCartEmpty()) { // Test isCartEmpty() method
        cout << "Number of items in cart1 " << cart1.getItemCount() << endl; // Tests getItemCount() method
        cout << "Total cost of items in cart1 $" << cart1.calcTotalCost() << endl; // Tests calcTotalCost() method
    }
    
    //To test the delete function
    cart1.deleteItem(it1);
    cart1.deleteItem(it3);
    cart1.deleteItem(it2);
    cout << "Number of items in cart1 " << cart1.getItemCount() << endl; 


    GroceryCart cart2;
    cart2.insertItem(it1);
    it4.setDescription("Coffee"); // Tests setDescription() method
    it4.setCost(7.5); //Test setCost method
    cout << it4; //Should print Coffee:$7.5. Tests << operator
    cart2.insertItem(it4);
    
    //To test the items inserted in cart2
    cout << cart2.getItemCount() << endl;
    
    // To check the == operator overloading
    GroceryCart cart3;
    cart3.insertItem(it1);
    cart3.insertItem(it2);

    GroceryCart cart4;
    cart4.insertItem(it1);
    cart4.insertItem(it2);

    if (cart3 == cart4) //Tests == operator
        cout << "Possibly duplicate carts" << endl;

    return 0;
    
    
}