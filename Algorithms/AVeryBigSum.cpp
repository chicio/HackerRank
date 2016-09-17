//
//  AVeryBigSum.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/a-very-big-sum

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> arr(n);
    unsigned long long sum = 0;
    
    for(int arr_i = 0;arr_i < n;arr_i++){
        
        cin >> arr[arr_i];
        sum += arr[arr_i];
    }
    
    cout << sum;
    
    return 0;
}
