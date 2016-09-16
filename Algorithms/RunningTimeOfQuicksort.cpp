//
//  RunningTimeofQuicksort.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/quicksort4

#include <vector>
#include <iostream>

using namespace std;

static int swapQuicksort = 0;
static int swapInsertionSort = 0;

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
            
            //Count swap quicksort.
            swapQuicksort++;
        }
    }
    
    swap(arr, i, high);

    //Count swap quicksort.
    swapQuicksort++;
    
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

/*
 Standard insertion sort implementation.
 
 @see https://en.wikipedia.org/wiki/Insertion_sort
 
 @param ar array to be sorted.
 */
void insertionSort(vector<int> ar) {
    
    int value;
    int j;
    
    for (int i = 1; i < ar.size(); i++) {
        
        value = ar[i];
        j = i - 1;
        
        while (j >= 0 && ar[j] > value) {
            
            swap(ar, j, j + 1);
            j--;
            
            //Count swap insertion sort.
            swapInsertionSort++;
        }
        
        ar[j + 1] = value;
    
    }
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < (int)n; ++i) {
        
        cin >> arr[i];
    }
    
    insertionSort(arr);
    quickSort(arr, 0, n - 1);
    
    cout << swapInsertionSort - swapQuicksort;
    
    return 0;
}
