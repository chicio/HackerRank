//
//  Quicksort1Partition.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 12/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/quicksort1

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> ar) {
    
    for (int i = 0; i < ar.size(); i++) {
        
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
 using Hoare partition scheme
 
 @see https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
 
 @param ar array to be partitioned.
 @param p pivot element and first element to be considered in the array.
 @param q last element to be considered in the array.
 */
void partition(vector<int>  ar, int p, int q) {
    
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
    
    printVector(ar);
}

int main(void) {

    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        
        cin >> _ar_tmp;
        
        _ar.push_back(_ar_tmp);
    }
    
    partition(_ar, 0, (int)_ar.size() - 1);
    
    return 0;
}
