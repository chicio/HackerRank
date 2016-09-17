//
//  ClosestsNumber.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 17/09/16.
//
//  https://www.hackerrank.com/challenges/closest-numbers

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> arr[i];
    }
    
    //Order array.
    sort(arr.begin(), arr.end());
    
    //Find min pairs.
    int minDiff = -1;
    int currentDiff;
    string output;
    
    for (int i = 0; i < n - 1; i++) {
        
        currentDiff = arr[i + 1] - arr[i];
    
        if(currentDiff == minDiff) {
            
            output += to_string(arr[i]) + " " +  to_string(arr[i + 1]) + " ";
        }

        if (currentDiff < minDiff || minDiff == -1) {

            output = to_string(arr[i]) + " " +  to_string(arr[i + 1]) + " ";
            minDiff = currentDiff;
        }
    }
    
    cout << output;
    
    return 0;
}
