//
//  FindtheMedian.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 18/09/16.
//
//  https://www.hackerrank.com/challenges/find-the-median

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(vector<int>& ar, int i, int j) {
    
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

int partition(vector<int>& arr, int low, int high, int pivotPosition) {
    
    int pivot = arr[pivotPosition];
    
    //Place pivot to the end.
    swap(arr, pivotPosition, high);
    
    int i = low;
    
    for (int j = low; j <= high; j++) {
        
        if(arr[j] < pivot) {
            
            swap(arr, i, j);
            i++;
        }
    }
    
    //Move pivot to its final position.
    swap(arr, high, i);
    
    return i;
}

/*!
 Quickselect implementation, also know as Hoare's selection algorithm.
 
 @see https://www.hackerrank.com/challenges/find-the-median
 
 @param arr array to be selected.
 @param low low index of subarray.
 @param high high index of subarray.
 @param n value to be find in ordered array.
 */
int quickSelect(vector<int>& arr, int low, int high, int n) {
 
    if(low == high) {
        
        //List of one element.
        return arr[low];
    }
    
    int pivotPosition = low + floor(rand() % (high - low));
    pivotPosition = partition(arr, low, high, pivotPosition);
    
    if (n == pivotPosition) {
        
        return arr[n];
    } else if (n < pivotPosition) {
        
        return quickSelect(arr, low, pivotPosition - 1, n);
    } else {
        
        return quickSelect(arr, pivotPosition + 1, high, n);
    }
}

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> arr[i];
    }
 
    cout << quickSelect(arr, 0, n - 1, n / 2) << endl;
    
    return 0;
}
