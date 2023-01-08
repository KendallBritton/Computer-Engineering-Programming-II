/* Use of dynamic memory to implement dynamic array (like vector) */
/* Feb 22 - Copy constructors */
#include <iostream>
using namespace std;

class MyVector {
private:
    int* arr; //only stores ints
    int size; // num elements
    int cap; // capacity - should >= num elements
public:
    MyVector() : arr{nullptr} {}; // Default constructor;
    MyVector(MyVector& inobj);  //Copy consturctor
    ~MyVector(); // Destructor: Cleans up stuff. Here deletes arr
    MyVector& operator=(MyVector& inobj);
    void push(int ele); // inserts element into vector
    friend ostream& operator <<(ostream& os, MyVector& v);
    
    
};


int main()
{
    MyVector vec;
    vec.push(1); //should store 1 in the vec
    vec.push(2); // should store 2 into the vec
    vec.push(10); 
    // vec.erase(0) // Erase element at position size
    cout << vec << endl; // should print all elements
    MyVector vec1(vec); //Input to vec1 is another MyVector object. This requires a copy constructor
    cout << vec1 << endl; // Should be same as vec
    vec1.push(42);
    cout << vec1 << endl; // Should be same as vec
    vec = vec1; // Copy vec1 into vec - requires a copy assignment oprator
    cout << vec << endl; // Should be same as vec
    
}

MyVector::~MyVector() // Destructor
{
    delete[] arr;
    cout << "Destroyed vector" << endl;
    
}

MyVector::MyVector(MyVector& inobj)
{
    //this->arr = inobj.arr; // arr belongs to vec1. Shallow copy. Only copying pointers
    this->arr = new int[inobj.cap]; // Create a whole new array for deep copying
    for (int i = 0; i < inobj.size; i++)// Now copy from input array
        this->arr[i] = inobj.arr[i];
    this->size = inobj.size;
    this->cap = inobj.cap;
    // this is a special pointer that points to the current object - here vec1.
   
}

MyVector& MyVector::operator=(MyVector& inobj)
{
    delete[] this->arr;
    this->arr = new int[inobj.cap]; // Create a whole new array for deep copying
    for (int i = 0; i < inobj.size; i++)// Now copy from input array
        this->arr[i] = inobj.arr[i];
    this->size = inobj.size;
    this->cap = inobj.cap;
    return *this;
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