//
//  LowerBoundSTL.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 23/08/16.
//
//  https://www.hackerrank.com/challenges/cpp-lower-bound

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    //n is the number of integer contained in the vector.
    //q is the number of queries.
    //y is the current query value.
    int n, q, y;
    
    cin >> n;
    
    //Get vector elements.
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> v[i];
    }
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        
        cin >> y;
        
        std::vector<int>::iterator position = lower_bound(v.begin(), v.end(), y);
        
        if(*position == y) {
            
            //Found int, print its position.
            cout << "Yes " << position - v.begin() + 1 << endl;
        } else {
            
            //Not found, print its lower bound.
            cout << "No " << lower_bound(v.begin(), v.end(), y) - v.begin() + 1 << endl;
        }
    }
}
