#include <iostream>
#include <vector>
using namespace std;

int main(){

    //int my_array[3] = {10,20,30};

    //vector<data_type> name_of_the_vector();

    vector<int> my_vector;

    //To add the elements in the vector

    my_vector.push_back(10);
    my_vector.push_back(20);
    my_vector.push_back(30);
    my_vector.push_back(40);
    my_vector.push_back(50);

    //To know the size of the vector

    cout << "The Vector size is: " << my_vector.size() << endl;
    cout << endl;

    for(int i = 0; i < my_vector.size(); i++){
        cout << "The vector elements are: " << i << " " << my_vector[i] << endl;
    }

    //To erase an element from the vector
    my_vector.erase(my_vector.begin() + 3);

    cout << endl;

    for(int i = 0; i < my_vector.size(); i++){
        cout << "The vector elements are: " << i << " " << my_vector[i] << endl;
    }

    //To insert an element in the vector

    my_vector.insert(my_vector.begin() + 3, 5);

    //To check to see if the vector is empty or not

    cout << endl;
    cout << "The Vector is: " << my_vector.empty() << endl;

    //To clear all the elements in the vector

    my_vector.clear();

    return 0;
}