//
//  SolveMeFirst.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/solve-me-first

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solveMeFirst(int a, int b) {
    
    return a + b;
}

int main() {
    
    int num1, num2;
    int sum;
    
    cin >> num1 >> num2;
    
    sum = solveMeFirst(num1,num2);
    
    cout<<sum;
    
    return 0;
}
