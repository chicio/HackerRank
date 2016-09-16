//
//  CompareTheTriplets.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/compare-the-triplets

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

void checkScores(int& alice, int& bob, int scoreA, int scoreB) {
    
    if(scoreA > scoreB) {
        
        alice++;
    } else if(scoreB > scoreA) {
        
        bob++;
    }
}

int main(){
    
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    
    int alice = 0;
    int bob = 0;
    
    checkScores(alice, bob, a0, b0);
    checkScores(alice, bob, a1, b1);
    checkScores(alice, bob, a2, b2);
    
    cout << alice << " " << bob;
    
    return 0;
}
