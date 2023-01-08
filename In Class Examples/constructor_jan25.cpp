#include <iostream>
using namespace std;

//create class
class BMI{
public:
//create constructor 
BMI(); //default constructor

//overload constructor
BMI(string, int, double);

//accessor Functions
string getName();
int getHeight();
double getWeight();

private:
//member variables
string newName;
int newHeight;
double newWeight;

};

//Function definitions
//class name :: constructor name()

BMI::BMI(){
    newHeight = 0;
    newWeight = 0.0;
}

BMI::BMI(string name, int height, double weight){
    newName = name;
    newHeight = height;
    newWeight = weight;
}

BMI::getName() {
    return newName;
}

BMI::getHeight() {
    return newHeight;
}

BMI::getWeight() {
    return newWeight;
}

int main(){
    
    string name;
    int height;
    double weight;

    cout << "Enter the name of the patient: ";
    getline(cin,name);
    cout << "Enter the height of the patient: ";
    cin >> height;
    cout << "Enter the weight of the ptient: ";
    cin >> weight;

    BMI student_1(name, height, weight);

    cout << "The Patient Name: " << student_1.getName() << endl;
    cout << "Height: " << student_1.getHeight() << endl; 
    cout << "Weight: " << student_1.getWeight() << endl;


    return 0;
}