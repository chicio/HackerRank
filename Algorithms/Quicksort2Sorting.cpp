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


void quickSort(vector <int> &ar) {
    
    if(ar.size() <= 1) {
        return;
    }
    
    vector<int> left;
    vector<int> right;

    int pivot = ar[0];
    
    for (int i = 1; i < ar.size(); ++i) {
        
        if(ar[i] <= pivot) {
            
            left.push_back(ar[i]);
        } else {
            
            right.push_back(ar[i]);
        }
    }
    
    quickSort(left);
    quickSort(right);
    
    ar.clear();
    ar.reserve(left.size() + right.size() + 1);
    ar.insert(ar.end(), left.begin(), left.end());
    ar.push_back(pivot);
    ar.insert(ar.end(), right.begin(), right.end());
    
    printVector(ar, 0, (int)ar.size() - 1);
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for(int i = 0; i < (int)n; ++i) {
        
        cin >> arr[i];
    }
    
    quickSort(arr);
    
    
    return 0;
}
