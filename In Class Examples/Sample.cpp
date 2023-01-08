#include <iostream>
using namespace std;

class Restaurant{
    public:
    void setName(string restaurantName);
    void setRating(int userRating);
    void print();
    private:
    string name;
    int rating;
};

void Restaurant :: setName(string restaurantName){
    name = restaurantName;
}

void Restaurant :: setRating(int userRating){
    rating = userRating;
}

void Restaurant :: print(){
    cout << name << "----" << rating << endl;
}

int main()
{
    Restaurant favLunchPlace;
    Restaurant favDinnerPlace;

    favLunchPlace.setName("central deli");
    favLunchPlace.setRating(4);

    favDinnerPlace.setName("Friends cafe");
    favDinnerPlace.setRating(5);

    cout << "My favorite place is:" << endl;
    favLunchPlace.print();
    favDinnerPlace.print();
    return 0;
}