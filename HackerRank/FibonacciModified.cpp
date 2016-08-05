//
//  FibonacciModified.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/07/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/fibonacci-modified

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    //t1 is the first base term for Fibonacci modified.
    //t1 is the second base term for Fibonacci modified.
    //n is the position of the term to be computed.
    unsigned long long t1, t2, n;
    
    //Read parameters.
    cin >> t1 >> t2 >> n;

    vector<unsigned long long> fibonacciModifiedSeries(n);
    fibonacciModifiedSeries[0] = t1;
    fibonacciModifiedSeries[1] = t2;
    
    for (int i = 2; i < n; i++) {
        
        fibonacciModifiedSeries[i] = fibonacciModifiedSeries[i - 2] + pow(fibonacciModifiedSeries[i - 1], 2);
    }
    
    cout << fibonacciModifiedSeries[n - 1];
    
    return 0;
}
