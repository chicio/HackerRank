//
//  2DArrays.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 22/09/2016.
//
//  https://www.hackerrank.com/challenges/2d-array

#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    vector<vector<int>> arr(6,vector<int>(6));
    
    for (int arr_i = 0; arr_i < 6; arr_i++){
        
        for (int arr_j = 0; arr_j < 6; arr_j++){
            
            cin >> arr[arr_i][arr_j];
        }
    }

    int maxSum = 0;
    int currentSum = 0;
    
    for (int i = 0; i < 4; i++) {
        
        for (int k = 0; k < 4; k++) {
            
            currentSum = arr[i][k] + arr[i][k + 1] + arr[i][k + 2];
            currentSum += arr[i + 1][k + 1];
            currentSum += arr[i + 2][k] + arr[i + 2][k + 1] + arr[i + 2][k + 2];
            
            if(currentSum > maxSum || (i == 0 && k == 0)) {
                
                maxSum = currentSum;
            }
        }
    }
    
    cout << maxSum;
    
    return 0;
}
