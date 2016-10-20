//
//  SparseArrays.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 20/10/2016.
//
//  https://www.hackerrank.com/challenges/sparse-arrays

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    //n is the number of strings.
    //q is the number of queries.
    int n, q;
    
    cin >> n;
    
    //Array of string.
    vector<string> ar(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> ar[i];
    }
    
    cin >> q;
    
    //String of the query.
    string stringToBeFound;
    
    for (int i = 0; i < q; i++) {
        
        cin >> stringToBeFound;

        int count = 0;
        
        for (int j = 0; j < n; j++) {

            if (ar[j] == stringToBeFound) {
                
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
