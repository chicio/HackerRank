//
//  Staircase.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/staircase

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    for(int row = 0; row < n; row++) {
        string output = "";
        
        int spaces;
        for(spaces = 0; spaces < (n - row) - 1; spaces++) {
            output += " ";
        }
        
        for(int k = spaces; k < n; k++) {
            output += "#";
        }
        
        cout << output << endl;
    }
    
    return 0;
}
