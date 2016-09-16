//
//  CountingSort1.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/countingsort1

#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n);

    
    for (int i = 0; i < n; ++i) {
        
        cin >> arr[i];
    }
    
    //Frequencies vector.
    vector<int> c(100, 0);
    
    for (int i = 0; i < n; ++i) {
        
        c[arr[i]]++;
    }
    
    for (int i = 0; i < (int)c.size(); i++) {
        
        cout << c[i] << " ";
    }
    
    return 0;
}
