//
//  CountingSort2.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/countingsort2

#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> ar, int min, int max) {
    
    for (int i = min; i <= max; i++) {
        
        cout << ar[i] << " ";
    }
    
    cout << endl;
}

/*!
 Standard counting sort implementation.
 
 @param arr vector to be sorted.
 */
void countingSort(vector<int>& arr) {
    
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 0; i < (int)arr.size(); i++) {
        
        if (arr[i] > max) {
            
            max = arr[i];
        }
        
        if (arr[i] < min) {
            
            min = arr[i];
        }
    }
    
    //Frequencies vector.
    vector<int> c(max - min + 1, 0);

    for (int i = 0; i < (int)arr.size(); i++) {
        
        c[arr[i] - min]++;
    }
    
    int k = 0;
    
    for (int i = 0; i < (int)c.size(); i++) {
        
        while (c[i] > 0) {
            
            arr[k] = i + min;
            k = k + 1;
            c[i]--;
        }
    }
}

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        
        cin >> arr[i];
    }
    
    countingSort(arr);
    
    printVector(arr, 0, (int)arr.size() - 1);
    
    return 0;
}
