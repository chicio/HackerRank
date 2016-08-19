//
//  ForLoop.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/08/16.
//
//  https://www.hackerrank.com/challenges/c-tutorial-for-loop

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    
    //Interval range.
    int a, b;
    
    //Read parameters.
    cin >> a >> b;
    
    //Array used to get word representation of numbers 1 <= N <= 9
    //(include also 0 to get straight conversion).
    string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for(int i = a; i <= b; i++) {
        
        if(i < 10) {
            
            //Number as word.
            cout << digits[i] << endl;
        } else if(i % 2 == 0) {
            
            //Even number.
            cout << "even" << endl;
        } else {
            
            //Odd number.
            cout << "odd" << endl;
        }
    }
    
    return 0;
}
