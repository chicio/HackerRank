//
//  DivisibleSumPairs.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 30/07/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/divisible-sum-pairs

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    
    //n is number of elements in the array.
    //k is the divisor to be tested.
    int n;
    int k;
    
    //Read input parameters.
    cin >> n >> k;
    vector<int> numbers(n);
    
    int sumModuleToBeChecked;
    int totalPairsEvenlyDivisible = 0;
    
    for(int i = 0; i < n; i++) {
        
        cin >> numbers[i];
        
        for(int h = 0; h < i; h++) {
            
            sumModuleToBeChecked = (numbers[i] + numbers[h]) % k;
            
            if(sumModuleToBeChecked == 0) {
                
                totalPairsEvenlyDivisible++;
            }
        }
    }
    
    cout << totalPairsEvenlyDivisible;
    
    return 0;
}
