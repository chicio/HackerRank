//
//  QuicksortInPlace.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 14/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/quicksort3

#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> ar, int min, int max) {
    
    for (int i = min; i <= max; i++) {
        
        cout << ar[i] << " ";
    }
    
    cout << endl;
}

void swap(vector<int>& ar, int i, int j) {
    
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}

/*
 Partition using Lomuto parition scheme.
 
 @param arr array to be sorted.
 @param low low index of subarray.
 @param high high index of subarray.
 
 @returns the new index of the pivot.
 */
int partition(vector<int>& arr, int low, int high) {
    
    int pivot = arr[high];
    int i = low;
    
    for (int j = low; j < high; j++) {
        
        if(arr[j] <= pivot) {
            
            swap(arr, i, j);
            i++;
        }
    }
    
    swap(arr, i, high);
    
    printVector(arr, 0, (int)arr.size() - 1);
    
    return i;
}

/*
 Quicksort implemented using Lomuto partition scheme.
 
 @see https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme
 
 @param low low index of subarray.
 @param high high index of subarray.
 */
void quickSort(vector<int>& arr, int low, int high) {
    
    if (low < high) {
        
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < (int)n; ++i) {
        
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);
    
    return 0;
}
