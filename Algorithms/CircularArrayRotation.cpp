//
//  CircularArrayRotation.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/circular-array-rotation

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    //n is the number of array element.
    //k is the number of array circle iteration.
    //q is the number of queries.
    int n, k, q;
    
    //Read parameters of the operations.
    cin >> n >> k >> q;
    
    //arr is the vector of integers.
    //arrRotated is the vector rotated.
    //queries is the vector of queries to be executed on the rotated array.
    vector<int> arr(n), arrRotated(n), queries(q);
    
    //Read array values.
    for(int i = 0; i < n; i++) {
        
        cin >> arr[i];
    }
    
    //Read queries.
    for(int i = 0; i < q; i++) {
        
        cin >> queries[i];
    }
    
    //Rotate arr k times.
    for(int h = 0; h < n; h++) {
        
        arrRotated[(h + k) % (n)] = arr[h];
    }
    
    //Print queries.
    for(int i = 0; i < q; i++) {
        
        cout << arrRotated[queries[i]] << endl;
    }
    
    return 0;
}
