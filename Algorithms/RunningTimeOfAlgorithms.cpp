//
//  RunningTimeOfAlgorithms.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 06/09/16.
//
//  https://www.hackerrank.com/challenges/runningtime

#include <vector>
#include <iostream>

using namespace std;

void insertionSort(vector<int> ar) {
    
    int steps = 0;
    
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
            
            //Count shifts
            steps++;
        }
        
        ar[j + 1] = value;
    }
    
    cout << steps;
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
