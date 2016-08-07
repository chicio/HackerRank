//
//  ConditionalStatements.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/08/16.
//
//  https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    //Number received as input.
    int n;
    
    //Read parameter.
    cin >> n;
    
    //Array used to get word representation of numbers 1 <= N <= 9
    //(include also 0 to get straight conversion).
    string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if(n < 10) {
        
        //Number as word.
        cout << digits[n];
    } else {
        
        //Message 'Greater than 9'
        cout << "Greater than 9";
    }
    
    return 0;
}
