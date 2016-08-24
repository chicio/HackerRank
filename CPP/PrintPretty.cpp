//
//  PrintPretty.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 24/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/prettyprint

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int T; cin >> T;
    
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    
    while(T--) {
        
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        cout << nouppercase << setw(0x0) << internal << showbase << hex << (long long)A << endl;
        cout << dec << right << showpos << setfill('_') << setw(0xf) << fixed << setprecision(2) << B << endl;
        cout << uppercase << noshowpos << setw(0x0) << setprecision(9) << scientific << C << endl;
    }
}
