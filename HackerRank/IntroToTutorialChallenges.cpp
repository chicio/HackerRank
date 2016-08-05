//
//  IntroToTutorialChallenges.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/07/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/tutorial-intro

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    //v is the value to be searched.
    //n is the size of the vector.
    int v, n;
    
    //Read parameters.
    cin >> v >> n;
    
    //Read vector values.
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> arr[i];
        
        if(arr[i] == v) {
            
            cout << i;
        }
    }
    
    return 0;
}
