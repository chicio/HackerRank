//
//  Kangaroo.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/kangaroo

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
    
    //x1 is first kangaroo starting position.
    //v1 is first kangaroo velocity.
    //x2 is second kangaroo starting position.
    //v1 is second kangaroo velocity.
    int x1;
    int v1;
    int x2;
    int v2;
    
    //Read parameters.
    cin >> x1 >> v1 >> x2 >> v2;
    
    //Check on v to avoid erroneous setup and
    //division by 0.
    if(v1 <= v2) {
        
        cout << "NO";
        return 0;
    }
    
    //Solve the following equation:
    //      x1 + (v1 * n) = x2 + (v2 * n)
    //Need to find the n variable (number of steps after
    //which the 2 kangaroos will meet each other).
    int numberOfJumps = (x2 - x1) / (v1 - v2);
    int moduleJumps = (x2 - x1) % (v1 - v2);
    
    //The 2 kangaroos will never land on the same location.
    if(numberOfJumps < 0 || moduleJumps != 0) {
        
        cout << "NO";
    } else {
        
        cout << "YES";
    }
    
    return 0;
}
