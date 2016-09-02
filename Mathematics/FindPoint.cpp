//
//  FindPoint.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/find-point

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    
    int nPoints;
    cin >> nPoints;
    
    Point a;
    Point b;
    
    for(int i = 0; i < nPoints; i++) {
        
        cin >> a.x >> a.y >> b.x >> b.y;
        
        Point symmetricPoint;
        symmetricPoint.x = a.x + (b.x - a.x) * 2;
        symmetricPoint.y = a.y + (b.y - a.y) * 2;
        
        cout << symmetricPoint.x << " " << symmetricPoint.y << "\n";
    }
    
    return 0;
}
