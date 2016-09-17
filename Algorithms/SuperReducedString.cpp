//
//  SuperReducedString.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/09/16.
//
//  https://www.hackerrank.com/challenges/reduced-string

#include <iostream>

using namespace std;

int main() {
    
    //String to be reduced.
    string s;
    
    //Read parameter.
    cin >> s;
    
    int i = 1;
    
    while (s.length() > 0 && i < s.length()) {
        
        if(s[i] == s[i - 1]) {
            
            //Same char on current and previous position.
            //Erase them and go back of 1 position.
            s.erase(i-- - 1, 2);
        } else {
            
            //Char not equal.
            //Go to next position.
            i++;
        }
    }
    
    cout << (s.length() > 0 ? s : "Empty String");
    
    return 0;
}
