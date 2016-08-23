//
//  SetsSTL.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 23/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/cpp-sets

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    //q is the number of query.
    //y is the type of query.
    //x is the value of the query.
    int q, y, x;
    set<int> s;
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        
        cin >> y >> x;
        
        switch (y) {
            case 1:
                s.insert(x);
                break;
            case 2:
                s.erase(x);
                break;
            case 3:
                cout << (*(s.lower_bound(x)) == x  ? "Yes" : "No") << endl;
                break;
        }
    }
    
    return 0;
}
