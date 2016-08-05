//
//  BitArray.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/bitset-1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    
    //Input parameters.
    unsigned int n, s, p, q;
    
    //Read parameters.
    cin >> n >> s >> p >> q;
    
    unsigned int bigInt = pow(2, 31);
    
    //Algorithm from pseudocode.
    unsigned int oldResult = s % bigInt;
    unsigned int result;
    unsigned int countResult = 1;
        
    for (int i = 1; i <= n - 1; i++) {
        
        result = (oldResult * p + q) % bigInt;
        
        if(result != oldResult) {
            
            countResult++;
            oldResult = result;
        } else {
            
            break;
        }
    }
    
    cout << countResult;
    
    return 0;
}
