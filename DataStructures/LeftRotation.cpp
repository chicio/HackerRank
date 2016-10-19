//
//  LeftRotation.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/10/2016.
//
//  https://www.hackerrank.com/challenges/array-left-rotation

#include <iostream>

using namespace std;

int main() {
    
    //n is the number of elements in the array.
    //r is the number of rotation to be performed.
    int n, r;
    
    cin >> n >> r;
    
    int array[n];
    int position;
    
    for (int i = 0; i < n; i++) {
        
        position = (i + (n - r)) % n;
        cin >> array[position];
    }
    
    for (int i = 0; i < n; i++) {
        
        cout << array[i] << " ";
    }
    
    return 0;
}
