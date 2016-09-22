//
//  ArraysDS.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 22/09/2016.
//
//  https://www.hackerrank.com/challenges/arrays-ds

#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    //n is elements in array.
    int n;
    
    cin >> n;
    
    //Read parameters.
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        
        cin >> arr[i];
    }
    
    for(int i = n - 1; i >= 0; i--) {
        
        cout << arr[i] << " ";
    }
    
    return 0;
}
