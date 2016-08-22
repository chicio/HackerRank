//
//  VectorErase.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 22/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/vector-erase

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    //n is the number of integer contained in the vector.
    //x is the position to be removed.
    //a is the start of the range to removed.
    //b is the end of the range to removed.
    int n, x, a, b;
    
    cin >> n;
    
    //Get vector elements.
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> v[i];
    }
    
    //Remove an element of the vector.
    cin >> x;
    
    v.erase(v.begin() + x - 1);
    
    //Remove a range from the vector.
    cin >> a >> b;
    
    v.erase(v.begin() + a - 1, v.begin() + b - 1);
    
    cout << v.size() << endl;
    
    for (int i = 0; i < v.size(); i++) {
        
        cout << v[i] << ' ';
    }
}
