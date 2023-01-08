#include <iostream>
using namespace std;

int sumDigits(int n); 

int main() 
{
    cout << sumDigits(1) << endl; // Should print 1
    cout << sumDigits(123) << endl; // Should print 6
    cout << sumDigits(57496) << endl; // Should print 31
    cout << sumDigits(777) << endl; // Should print 21
    return 0;
    
}

int sumDigits(int n) {
 // Your recursive code here - 
 if(n<10){
     return n;
 } else {
     return (n%10) + sumDigits(n/10);
 }   
}