//
//  SortingBubbleSort.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 26/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-bubble-sort

#include <vector>
#include <iostream>

using namespace std;

/*!
 Similar to challenge https://www.hackerrank.com/challenges/new-year-chaos
 */

/*!
 Bubble sort with total count of swap executed.
 
 @param a vector to be sorted (reference).
 @param n number of element in vector.
 
 @returns total number of swaps.
 */
int bubbleSort(vector<int>& a, int n) {
    
    int totalNumberOfSwap = 0;
    
    for (int i = 0; i < n; i++) {
        
        //Swaps in single traversal.
        int numberOfSwaps = 0;
        
        for (int j = 0; j < n - 1; j++) {
            
            if (a[j] > a[j + 1]) {
                
                //Swap adjacent element if in descending order.
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }
        
        //No swap, so vector is sorted.
        if (numberOfSwaps == 0) {
            
            break;
        }
        
        totalNumberOfSwap += numberOfSwaps;
    }
    
    return totalNumberOfSwap;
}

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> a(n);
    
    for (int a_i = 0;a_i < n;a_i++) {
        
        cin >> a[a_i];
    }
    
    //Sort array with bubble sort.
    int totalNumberOfSwap = bubbleSort(a, n);
    
    cout << "Array is sorted in " << totalNumberOfSwap  << " swaps." << endl;
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1] << endl;
    
    return 0;
}
