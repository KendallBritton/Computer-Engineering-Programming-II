#include <iostream>
using namespace std;

class fraction{
    private:
    int numerator, denominator;
    public:
    fraction(int x, int y):numerator{x}, denominator{y} {} //Constructor to assign values while initializing. Same name class and no return type
    fraction():numerator{1},denominator{1} {} //Default contructor. We now have multiple constructors. This is called overloading.
    void setNumerator(int x){
        numerator = x;
    }
    void setDenominator(int y);
    int getNumerator(){
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }
};

void fraction::setDenominator(int y){
    if (y == 0){
        denominator = 1;
    } else {
        denominator = y;
    }
}

int main(){
 fraction f1(1,2), f2(2,4);

/*
 f1.setNumerator(1);
 f1.setDenominator(0);
 f2.setNumerator(1);
 f2.setDenominator(4);
 */

 cout << f1.getNumerator() << endl;
 cout << f1.getDenominator() << endl;
 cout << f2.getNumerator() << endl;
 cout << f2.getDenominator() << endl;

return 0;
}