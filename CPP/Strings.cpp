//
//  Strings.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/c-tutorial-strings

#include <iostream>
#include <string>

using namespace std;

int main() {

    //Input strings.
    string a, b;
    
    //Read parameters.
    cin >> a >> b;
    
    //Print stirng length.
    //C++ has length (so I don't use size() as stated in the problem statement)
    cout << a.length() << " " << b.length() << endl;
    
    //Concatenation.
    cout << a + b << endl;
    
    //Swapped string (use substr to get substring of string).
    cout << b[0] + a.substr(1) << " " << a[0] + b.substr(1) << endl;
}
