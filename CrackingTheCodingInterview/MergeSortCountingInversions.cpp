//
//  MergeSortCountingInversions.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 28/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-merge-sort

#include <vector>
#include <iostream>

using namespace std;

/// Simple static variable used to count the number of inversions.
static unsigned long countInversion;

/*!
 Merge subarray function.

 @param array the array to be sorted (passed as reference).
 @param leftStart the start of the subarray to be sorted.
 @param rightEnd the end of the subarray to be sorted.
 */
void merge(vector<int>& array, unsigned long leftStart, unsigned long rightEnd) {
    
    vector<int> temp(rightEnd - leftStart + 1);
    
    unsigned long leftEnd = (rightEnd + leftStart) / 2;
    unsigned long rightStart = leftEnd + 1;

    unsigned long left = leftStart;
    unsigned long right = rightStart;
    unsigned long index = 0;
    
    while (left <= leftEnd && right <= rightEnd) {
        
        if (array[left] <= array[right]) {
            
            temp[index] = array[left];
            left++;
        } else {
            
            temp[index] = array[right];
            right++;
            
            //Variable not needed in standard mergesort.
            //Count the number of inversion.
            //The number of start is the nnumber of place
            //an element in the right array is moved (because is
            //greater than the ones in the left).
            countInversion = countInversion + (rightStart - left);
        }
        
        index++;
    }
    
    //If left element remain, add them (if we enter here
    //next loop is not executed (see first while condition)).
    while (left <= leftEnd) {
        
        temp[index] = array[left];
        left++;
        index++;
    }
    
    //If right element remain, add them (if we enter here
    //previous loop is not executed (see first while condition)).
    while (right <= rightEnd) {
        
        temp[index] = array[right];
        right++;
        index++;
    }
    
    //Copy back values of temp in array.
    for (unsigned long i = leftStart; i <= rightEnd; i++) {

        array[i] = temp[i - leftStart];
    }
}

/*!
 Merge sort main function.
 
 @param array the array to be sorted (passed as reference).
 @param leftStart the start of the subarray to be sorted.
 @param rightEnd the end of the subarray to be sorted.
 */
void mergesort(vector<int>& array, unsigned long leftStart, unsigned long rightEnd) {

    if (leftStart >= rightEnd) {
        
        return;
    }
    
    unsigned long middle = (leftStart + rightEnd) / 2;
    
    mergesort(array, leftStart, middle);
    mergesort(array, middle + 1, rightEnd);
    merge(array, leftStart, rightEnd);
}

/*!
 Implements merge sort.
 
 @param array the array to be sorted (passed as reference).
 */
void mergesort(vector<int>& array) {
    
    mergesort(array, 0, array.size() - 1);
}

long long count_inversions(vector<int> a) {
 
    //Reset count of inversion.
    countInversion = 0;
    
    mergesort(a);
    
    return countInversion;
}

int main() {
    
    int t;
    
    cin >> t;
    
    for (int a0 = 0; a0 < t; a0++) {
        
        int n;
        
        cin >> n;
        
        vector<int> arr(n);
        
        for (int arr_i = 0; arr_i < n; arr_i++) {
            
            cin >> arr[arr_i];
        }
        
        cout << count_inversions(arr) << endl;
    }

    return 0;
}
