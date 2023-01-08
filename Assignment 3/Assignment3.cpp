/* Use of dynamic memory to implement dynamic array (like vector) */

#include <iostream>
using namespace std;

class MyVector {
private:
    int* arr; //only stores ints
    int size;
    int cap;
public:
    MyVector() : arr{nullptr} {}; // Default constructor;
    ~MyVector(); // Destructor: Cleans up stuff. Here deletes arr
    void push(int ele); // inserts element into vector
    friend ostream& operator <<(ostream& os, MyVector& v);
    void erase(int pos);
    
    
};


int main()
{
    MyVector vec;
    vec.push(1); //should store 1 in the vec
    vec.push(2); // should store 2 into the vec
    vec.push(10); // should print all elements
    vec.erase(0); // Erase element at position 0
    cout << vec << endl; // should print remaining elements
    
}

MyVector::~MyVector() // Destructor
{
    delete[] arr;
    cout << "Destroyed vector" << endl;
    
}

ostream& operator <<(ostream& os, MyVector& v)
{
    for(int i = 0; i < v.size; i++)
        os << v.arr[i] << " ";
    return os;
}

void MyVector::push(int ele)
{
    // Check if arr == nullptr. If yes, dynamically create an array of elements. Insert ele into array
    if (arr == nullptr) {
        cap = 2;
        arr = new int[cap];
        arr[0] = ele;
        size = 1;
    }
    else {
        // Check if there is space
        if (size < cap) {
            arr[size] = ele;
            size++;
        }
        else {
            int* temp = arr;
            arr = new int[2*cap];
            for (int i = 0; i < cap; i++)
                arr[i] = temp[i];
            delete[] temp;
            cap = 2*cap;
            arr[size] = ele;
            size++;
        }

    }
    
}

void MyVector::erase(int pos){
    int* temp = arr;
    arr = new int[cap];
    for (int i = 0 + pos; i < cap; i++){
        arr[i] = temp[i+1];
    }
    delete[] temp;
    size--;
}