//
//  InsertionSortPart1.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 04/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/insertionsort1

#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> ar) {
    
    for (int i = 0; i < ar.size(); i++) {
        
        cout << ar[i] << " ";
    }
}

void insertionSort(vector<int> ar) {

    int i = (int)(ar.size() - 1);
    int j = (int)(ar.size() - 2);
    int value = ar[ar.size() - 1];
    
    while (j >= 0 && ar[j] > value) {
        
        ar[i] = ar[j];
        
        printVector(ar);
        cout << endl;
        
        i--;
        j--;
    }
    
    ar[i] = value;
    
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
    
    insertionSort(_ar);
    
    return 0;
}
