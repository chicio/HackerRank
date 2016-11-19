//
//  VariableSizedArrays.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 03/08/16.
//
//  https://www.hackerrank.com/challenges/variable-sized-arrays

#include <iostream>

using namespace std;

int main() {
    
    //n is the number of sequences.
    //q is the number of queries.
    //k is the number of elements in the current array received as input.
    int n, q, k;
    
    //Pointer to array of pointers (pointer to pointer).
    int** arrays;
    
    cin >> n >> q;

    arrays = new int* [n];
    
    for (int i = 0; i < n; i++) {
        
        cin >> k;

        arrays[i] = new int[k];
        
        for(int j=0; j<k; j++) {
            
            cin >> arrays[i][j];
        }
    }
    
    //Queries indexes received as input.
    int a, b;
    
    for (int i = 0; i < q; i++) {
        
        cin >> a >> b;
        cout << arrays[a][b] << endl;
    }
    
    return 0;
}
