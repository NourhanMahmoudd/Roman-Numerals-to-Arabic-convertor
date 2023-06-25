//Faculty of Computers and Artificial Intelligence (FCAI-CU)
//Programming 1 - 2022 - Assignment 2
//Roman Numerals to Arabic convertor
/*Program Description: This program converts Roman numerals to Arabic numbers
These are the Roman numerals used in the program
I  1
V  5
X  10
L  50
C  100
D  500
M  1000
In Roman numerals num= yz if Y<Z num = y-z  else num = y+z*/
//By: Nourhan Mahmoud 
//Purpose:Converting Roman numerals to Arabic numbers


#include <iostream>
#include <map>
#include <cctype> // For character case conversion

using namespace std;

int romanToArabic(const string& roman) {
    map<char, int> rmap{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };

    int number = 0;

    // If user enters only one character, return the value in the map
    if (roman.length() == 1) {
        return rmap.at(toupper(roman[0])); // Convert to uppercase
    } else {
        for (int i = 0; i < roman.size(); i++) {
            if (rmap[toupper(roman[i])] < rmap[toupper(roman[i + 1])]) { 
                number += rmap[toupper(roman[i + 1])] - rmap[toupper(roman[i])]; 
                i++; // Skip the next character since it has already been processed
            } else {
                number += rmap[toupper(roman[i])]; // Convert to uppercase
            }
        }
        return number;
    }
}

int main() {
    string roman;
    cout << "Welcome to the Roman to Arabic numbers converter!\n";
    cout << "Please enter your Roman number: ";
    getline(cin, roman);

    cout << "The Arabic form is: " << romanToArabic(roman) << endl;

    return 0;
}
