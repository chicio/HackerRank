//
//  InsertionSortPart2.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 05/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/insertionsort2

#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> ar) {
    
    for (int i = 0; i < ar.size(); i++) {
        
        cout << ar[i] << " ";
    }
    
    cout << endl;
}

/*
 Standard insertion sort implementation.
 
 @see https://en.wikipedia.org/wiki/Insertion_sort
 
 @param ar array to be sorted.
 */
void insertionSort(vector<int> ar) {
    
    int value;
    int j;
    int temp;
    
    for (int i = 1; i < ar.size(); i++) {
        
        value = ar[i];
        j = i - 1;
        
        while (j >= 0 && ar[j] > value) {
            
            temp = ar[j + 1];
            ar[j + 1] = ar[j];
            ar[j] = temp;
            
            j--;
        }
        
        ar[j + 1] = value;
        
        printVector(ar);
    }
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
    
    insertionSort(_ar);
    
    return 0;
}
