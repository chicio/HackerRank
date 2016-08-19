//
//  FlatlandSpaceStations.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/flatland-space-stations

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

int main() {
    
    //n is the number of cities.
    //m is the number of space stations.
    int n;
    int m;
    
    //Read parameters.
    cin >> n >> m;
    
    //There's a space station for each city: distance max is 0.
    if(n == m) {
        
        cout << 0;
        return 0;
    }
    
    //Vector of space stations.
    vector<int> c(m);
    
    for(int c_i = 0; c_i < m; c_i++){
        
        cin >> c[c_i];
    }
    
    int maxDistance = 0;
    
    //Foreach cities.
    for(int i = 0; i < n; i++) {
        
        int nearest = abs(i - c[0]);
        
        //Calculate nearest space station from the current i city.
        for(int h = 1; h < m; h++) {
            
            nearest = min(nearest, abs(i - c[h]));
        }
        
        //Check if nearest space station for current city has a distance > than current max distance.
        maxDistance = max(maxDistance, nearest);
    }
    
    cout << maxDistance;
    
    return 0;
}
