//
//  MaximumDraws.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//
//  https://www.hackerrank.com/challenges/maximum-draws

#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    //t is the number of test cases.
    //n is the number of socks in the drawer.
    int t, n;
    
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        
        cin >> n;
        
        cout << n + 1 << endl;
    }
    
    return 0;
}
