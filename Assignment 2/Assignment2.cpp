/* Counter Class*/

#include <iostream>

using std::cout;
using std::endl;

using namespace std;

class CounterType{
//Write the declaration for the class
private:
int num;

public:
CounterType():num{0}{}
void setCount(int num);
int getCount();
void incCount();
void decCount();
friend ostream& operator<<(ostream& os, CounterType& ctr);
};


int main()
{
    CounterType ctr;
    ctr.setCount(1); // Set count to 1
    cout << ctr.getCount() << endl; // Outputs count
    ctr.incCount(); // Increments count
    cout << ctr.getCount() << endl; // Verify increment worked correctly
    ctr.decCount(); // Decrement count
    ctr.decCount(); // Decrement count
    cout << ctr.getCount() << endl; // Verify decrement worked correctly
    ctr.decCount(); // Decrement count // Should print Invalid Operation
    return 0;

}

//Define the class member functions as specified by the test in main() - setCount(), getCount(), incCount(), decCount().

void CounterType::setCount(int n){
num = n;
}

int CounterType::getCount(){
return num;
}

void CounterType::incCount(){
num = num + 1;
}

void CounterType::decCount(){
    if(num > 0){
       num = num - 1; 
    } else {
        cout << "Invalid Operation" << endl;
    }
 
}

ostream& operator<<(ostream& os, CounterType& ctr){
    os << ctr.getCount() << endl;
    return os;
}