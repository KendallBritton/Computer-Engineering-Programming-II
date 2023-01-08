#include <iostream>
#include <cstring>
using namespace std;

#include "mystring.h"

MyString::MyString(){
    str = nullptr;
    len = 0;
}

MyString::~MyString(){  //Destructor 
delete[] str;
cout << "Destroyed string" << endl;
}

MyString::MyString(const char* s){
int i = 0;
const char* t = s;
while(*s++){
    i++;
}

str = new char[i];
int j = 0;

for(j;*t;t++){
    j++;
    str[j] = *t;
}
len = j + 1;

}

MyString::MyString(MyString& s){
len = s.len + 1;
str = new char[len];
for(int i = 0; i < len; i++){
    str[i] = s.str[i];
}
}

ostream& operator <<(ostream& os, MyString& s){ // prints string
    for(int i = 0; i < s.len; i++){
        os << s.str[i];
    }
    return os;
}

MyString& MyString::operator +(MyString& s){  //Creates a new string by concantenating input string
int len = len + s.len + 1;
char* str = new char[len];
for(int i = 0; i < len; i++){
    str[i] = str[i];
}
delete[] str;
for(int i = 0; i < len; i++){
    str[i] = s.str[i];
}
return *this;
}

MyString& MyString::operator =(MyString& s){  //Copy Assignment
    str = s.str;
}