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
//By: Nourhan Mahmoud ID: 20211107 Group:A
//Teaching Assistant:
//Purpose:Converting Roman numerals to Arabic numbers


#include<iostream>
#include <bits/stdc++.h>

using namespace std;
// creating a function that converts roman numerals into arabic numbers
//first create a map that converts every Roman numeral into its Arabic form
int roman_to_int(string roman){
    map<char,int> rmap;
    rmap['I'] =   1;
    rmap['V'] =   5;
    rmap['X'] =  10;
    rmap['L'] =  50;
    rmap['C'] = 100;
    rmap['D'] = 500;
    rmap['M'] =1000;
    int number=0,i=0;

    //If user enters only one character then show the value in the map
    if(roman.length()<=1){
        return rmap[roman.at(0)];
        //at() returns a reference to the element at the given location
    }
    else{
        // compare i with the number of elements by .size()
        //In Roman numerals num= yz if Y<Z num = y-z  else num = y+z, so we'll compare each index with the next one

        while(i<roman.size()){
            if(rmap[roman[i]]<rmap[roman[i+1]]){
                number+=rmap[roman[i+1]]-rmap[roman[i]];
                i+=2;
            }
            else{
                number+=rmap[roman[i]];
                i++;
            }
        }
        return number;
    }
}

int main(){
    string roman;
    cout << "Welcome to Roman to Arabic numbers convertor! \n ";

    cout<<"Please enter your Roman number (Capital only): ";
    getline(cin,roman);

    int arabic;
    arabic =roman_to_int(roman);

    cout<<"The Arabic form is : "<< arabic << endl;


    return 0;
}