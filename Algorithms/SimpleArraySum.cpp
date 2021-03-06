//
//  SimpleArraySum.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/simple-array-sum

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    int sum = 0;
    
    //Get array size.
    cin >> n;
    
    //Init array.
    vector<int> arr(n);
    
    //Read values and sum them.
    for(int arr_i = 0;arr_i < n;arr_i++){
        
        cin >> arr[arr_i];
        sum = sum + arr[arr_i];
    }
    
    cout << sum;
    
    return 0;
}
