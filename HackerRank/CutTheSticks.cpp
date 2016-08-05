//
//  CutTheSticks.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/07/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/cut-the-sticks

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    //n is the number of elements in array.
    int n;
    
    //Read parameter.
    cin >> n;
    
    //Read array values.
    vector<int> arr(n);
    
    for(int arr_i = 0; arr_i < n; arr_i++) {
        
        cin >> arr[arr_i];
    }
    
    //Number of current cut off executed.
    int cutOffExecuted = n;
    
    //Current cut off lenght.
    int minElement;
    
    //Update incrementaly the array.
    while (arr.size() > 0) {
        
        //Set up cut off lenght and number of cut of executed.
        minElement = *min_element(arr.begin(), arr.end());
        cutOffExecuted = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            
            //Update element with current min cut off (minElement).
            arr[i] -= minElement;
            cutOffExecuted++;
        }
        
        arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
        
        cout << cutOffExecuted << endl;
    }
    
    return 0;
}
