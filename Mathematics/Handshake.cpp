//
//  Handshake.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/09/16.
//
//  https://www.hackerrank.com/challenges/handshake

#include <cmath>
#include <iostream>

using namespace std;

/*
 In the previous version I used the
 standard Binomial coefficient formula.
 But there's a more efficient multiplicative 
 formula that could be used:
 
 https://en.wikipedia.org/wiki/Binomial_coefficient#Multiplicative_formula
 
 Expanding the multiplicative formula for k = 2
 gives the following formula:
 
    binomial_coefficient = (n^2 - n) / 2
 
 This is the formula used below to compute the 
 number of handshakes between board members.
 */
int main() {
    
    int t;
    
    cin >> t;
    
    unsigned long long n;
    
    for(int i = 0; i < t; i++) {
        
        cin >> n;
        
        unsigned long long handshakes = (pow(n, 2) - n) / 2;
        
        cout << handshakes << endl;
    }
    
    return 0;
}
