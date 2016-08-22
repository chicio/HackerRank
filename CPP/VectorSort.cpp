//
//  VectorSort.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 22/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/vector-sort

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    //n is the number of integer contained in the vector.
    int n;
    
    cin >> n;
    
    //Get vector elements.
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> v[i];
    }
    
    //Sort vector.
    sort(v.begin(), v.end());
    
    for (int i = 0; i < n; i++) {
        
        cout << v[i] << ' ';
    }
    
    return 0;
}
