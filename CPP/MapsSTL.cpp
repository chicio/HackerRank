//
//  MapsSTL.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 23/08/16.
//
//  https://www.hackerrank.com/challenges/cpp-maps

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {

    //q is the number of queries.
    //t is the type of query.
    //y is the mark of the student in the query.
    //x is the name of the student in the query.
    int q, t, y;
    string x;
    map<string, int> m;
    
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        
        cin >> t >> x;
        
        switch (t) {
            case 1:
                cin >> y;
                m[x] = m[x] + y;
                break;
            case 2:
                m.erase(x);
                break;
            case 3:
                cout << (m.count(x) == 1 ? m[x] : 0) << endl;
                break;
        }
        
    }
    
    return 0;
}
