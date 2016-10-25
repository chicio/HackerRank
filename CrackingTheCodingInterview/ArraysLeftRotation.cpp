//
//  ArraysLeftRotation.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 26/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-array-left-rotation

#include <vector>
#include <iostream>

using namespace std;

/*!
 Vector left rotation.
 Same challenge as https://www.hackerrank.com/challenges/array-left-rotation
 */
vector<int> arrayLeftRotation(vector<int> a, int n, int k) {
    
    vector<int> array(n);
    int position;
    
    for (int i = 0; i < n; i++) {
        
        position = (i + (n - k)) % n;
        array[position] = a[i];
    }

    return array;
}

int main() {
    
    int n;
    int k;
    
    cin >> n >> k;
    
    vector<int> a(n);
    
    for (int a_i = 0;a_i < n; a_i++) {
        
        cin >> a[a_i];
    }
    
    vector<int> output = arrayLeftRotation(a, n, k);
    
    for (int i = 0; i < n; i++) {
        
        cout << output[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
