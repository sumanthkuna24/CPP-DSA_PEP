// reference.cpp
// Day 1: Basic C++ syntax and input-output reference

#include <iostream>
using namespace std;

int main() {
   
    int a;
    float b;
    char c;

 
    cout << "Enter an integer value: ";
    cin >> a;

    cout << "Enter a float value: ";
    cin >> b;

    cout << "Enter a character: ";
    cin >> c;

    cout << "\nYou entered:\n";
    cout << "Integer value: " << a << endl;
    cout << "Float value  : " << b << endl;
    cout << "Character    : " << c << endl;

    return 0;
}
