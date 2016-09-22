//
//  PossiblePath.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 22/09/2016.
//
//  https://www.hackerrank.com/challenges/possible-path

#include <iostream>

using namespace std;

/**
 Recursive GCD (greatest common divisor) Euclidean Agorithm 
 between two numbers.
 
 @see https://en.wikipedia.org/wiki/Euclidean_algorithm#Implementations
 
 @param a first number.
 @param b second number.
 
 @returns the gcd of the two numbers.
 */
int gcd(unsigned a, unsigned b) {
    
    if (b == 0) {
        
        return a;
    }
    
    return gcd(b, a % b);
}

int main() {
    
    int t;
    
    cin >> t;
    
    int x1;
    int y1;
    int x2;
    int y2;
    
    for (int i = 0; i < t; i++) {
        
        cin >> x1 >> y1 >> x2 >> y2;

        if (gcd(x1, y1) == gcd(x2, y2)) {
            
            cout << "YES" << endl;
        } else {
            
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
