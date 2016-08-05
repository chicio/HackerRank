//
//  NonDivisibleSubset.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/07/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/non-divisible-subset

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main(){

    //n is the number of elements in the array.
    //k is the number to use as test for division.
    int n, k;
    
    //Read parameters.
    cin >> n >> k;
    
    //Read array values.
    vector<int> arr(n);
    map<int, vector<int>> remaindersSets;
    
    for(int arr_i = 0; arr_i < n; arr_i++) {
        
        cin >> arr[arr_i];
        remaindersSets[arr[arr_i] % k].push_back(arr[arr_i]);
    }
    
    vector<int> maximumSet(0);
    
    //Use remainders rule to create the maximum set.
    //Remeber:
    // given two numbers i1 and i2, their sum is divisible by k
    // only if their remainder is divisible by k.
    for(int i = 1; i <= k / 2; i++) {
        
        if(i != k / 2 || k % 2 != 0) {
            
            if(remaindersSets[i].size() >= remaindersSets[k - i].size()) {
            
                maximumSet.insert(maximumSet.end(), remaindersSets[i].begin(), remaindersSets[i].end());
            } else {
            
                maximumSet.insert(maximumSet.end(), remaindersSets[k - i].begin(), remaindersSets[k - i].end());
            }
        } else {
            
            maximumSet.push_back(remaindersSets[i][0]);
        }
    }
    
    //Add one element for evenly divisble set (if exists).
    if(!(remaindersSets.find(0) == remaindersSets.end())) {

        maximumSet.push_back(remaindersSets[0][0]);
    }
    
    cout << maximumSet.size();
    
    return 0;
}
