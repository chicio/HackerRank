//
//  Quicksort2Sorting.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 12/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//

#include <iostream>
#include <vector>

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
 Standard quicksort partition function implementation
 using Hoare partition scheme, returning the j position of the pivot.
 
 @see https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 
 @param ar array to be partitioned.
 @param p pivot element and first element to be considered in the array.
 @param q last element to be considered in the array.
 
 @return j, the new position of the pivot.
 */
int partition(vector<int>&  ar, int p, int q) {
    
    int i = p;
    int j = q;
    
    //ar[p] is the pivot element.
    while (i <= j) {
        
        while(ar[j] > ar[p]) {
            
            j--;
        }
        
        while (ar[i] <= ar[p] && i <= j) {
            
            i++;
        }
        
        if (i < j) {
            
            swap(ar, i, j);
            i++;
            j--;
        }
    }
    
    swap(ar, p, j);
    
    return j;
}

void quickSort(vector <int> &ar, int low, int high) {


    if(low < high) {
        
        int p = partition(ar, low, high);
        quickSort(ar, low, p);
        quickSort(ar, p + 1, high);

        printVector(ar, low, high);
    }
}

int main() {
    
    int n;
    cin >> n;
    
    vector <int> arr(n);
    
    for(int i = 0; i < (int)n; ++i) {
        
        cin >> arr[i];
    }
    
    quickSort(arr, 0, (int)arr.size() - 1);
    
    printVector(arr, 0, (int)arr.size() - 1);
    
    return 0;
}
