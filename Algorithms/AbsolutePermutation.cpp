//
//  AbsolutePermutation.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/absolute-permutation

#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    //t is the number of test cases.
    //n is the range from 1 of natural numbers to be considered.
    //k is the distance of each natural number from its original position.
    int t, n, k;
    
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        
        cin >> n >> k;
        
        //Case 1: k = 0, so no distance, so print original series.
        if(k == 0) {
            
            for(int h = 1; h <= n; h++) {
                
                cout << h << ' ';
            }
            
            cout << endl;
            
            continue;
        }
        
        //Case 2: n is not divisible by k, so no permutation with absolute distance = k for each pos, so print -1.
        if(n % k != 0) {
            
            cout << -1 << endl;
            
            continue;
        }
        
        //Case 3: permutation exists so print the permuted series.
        vector<int> permutation(n);
        int numberOfSubset = n / (k * 2);
        int startSubset, endSubset;
        
        for(int h = 0; h < numberOfSubset; h++) {
            
            startSubset = k * 2 * h;
            endSubset = startSubset + k;
            
            for(int z = startSubset; z < endSubset; z++) {
                
                permutation[z] = z + k + 1;
                permutation[z + k] = z + 1;
            }
        }
        
        for(int h = 0; h < n; h++) {
            
            cout << permutation[h] << ' ';
        }
        
        cout << endl;
    }
    
    return 0;
}
