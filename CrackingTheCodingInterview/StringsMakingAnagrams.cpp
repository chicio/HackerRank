//
//  StringsMakingAnagrams.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 26/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-making-anagrams

#include <string>
#include <iostream>

using namespace std;

int numberNeeded(string a, string b) {
    
//    int totalErase = 0;
//    string* maxLengthString;
//    string* minLengthString;
//    
//    if (a.length() > b.length()) {
//        
//        maxLengthString = &a;
//        minLengthString = &b;
//    } else {
//
//        maxLengthString = &b;
//        minLengthString = &a;
//    }
//    
//    
//    for (int i = 0; i < maxLengthString->length(); i++) {
//        
//        bool found = false;
//        
//        for (int k = 0; k < minLengthString->length(); k++) {
//            
//            if (maxLengthString[i] == minLengthString[k]) {
//                
//                found = true;
//            }
//        }
//        
//        if (!found) {
//            
//            maxLengthString->erase();
//        }
//    }
//    
    
    int totalErase = 0;
    
    for (int i = 0; i < a.length(); i++) {
        
        bool found = false;
        
        for (int k = 0; k < b.length(); k++) {
            
            if (a[i] != b[k]) {
                
                found = true;
            }
        }
        
        if (!found) {
            
            a.erase(i, 1);
            totalErase++;
        }
    }
    
    for (int i = 0; i < b.length(); i++) {
        
        bool found = false;
        
        for (int k = 0; k < a.length(); k++) {
            
            if (b[i] != a[k]) {
                
                found = true;
            }
        }
        
        if (!found) {
            
            b.erase(i, 1);
            totalErase++;
        }
    }

    return totalErase;
}

int main() {
    
    string a;
    string b;
    
    cin >> a;
    cin >> b;
    
    cout << numberNeeded(a, b) << endl;
    
    return 0;
}
