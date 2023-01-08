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

    friend fraction operator+(fraction& f1, fraction& f2); //Not part of class - outside it. But is a friend of the class
    //Friends - can access private data without being part of the class. No neeed to use getters and setters
    friend ostream& operator<<(ostream& os, fraction& f);
};

void fraction::setDenominator(int y){
    if (y == 0){
        denominator = 1;
    } else {
        denominator = y;
    }
}

fraction operator+(fraction& f1, fraction& f2){
    fraction res;
    res.numerator = f1.numerator*f2.denominator + f1.denominator*f2.numerator;
    res.denominator = f1.denominator*f2.denominator;
    return res;
}

ostream& operator<<(ostream& os, fraction& f){
    os << f.numerator << "/" << f.denominator << endl;
    return os;
}

int main(){
 fraction f1(1,2), f2(1,4), f3;
 f3 = f1 + f2;
 cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
 cout << f3;


return 0;
}