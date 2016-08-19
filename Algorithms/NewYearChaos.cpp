//
//  NewYearChaos.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/new-year-chaos

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
    
    //t is th number of test cases.
    int T;
    
    //Read parameter.
    cin >> T;
    
    //Foreach test case.
    for(int a0 = 0; a0 < T; a0++) {
        
        //n is the number of element in the queue of the current test case.
        int n;
        
        //Read parameter.
        cin >> n;
        
        vector<int> q(n);
        vector<int> swapPerPerson(n);
        
        for(int q_i = 0; q_i < n; q_i++) {
            
            cin >> q[q_i];
            swapPerPerson[q_i] = 0;
        }
        
        bool swapped = true;
        bool tooChaotic = false;
        
        //Bubble sort with count of swap per element.
        while(swapped && !tooChaotic) {
            
            swapped = false;
            
            for(int i = 1; i < n; i++) {
                
                if(q[i - 1] > q[i]) {
                    
                    swap(q[i - 1], q[i]);
                    swapPerPerson[q[i] - 1]++;
                    swapped = true;
                    
                    if(swapPerPerson[q[i] - 1] > 2) {
                        
                        tooChaotic = true;
                    }
                }
            }
        }
        
        if(tooChaotic) {
            
            cout << "Too chaotic" << endl;
            continue;
        }
        
        //Count total number of bribe.
        int totalBribes = 0;
        
        for(int i = 0; i < n; i++) {
            
            totalBribes += swapPerPerson[i];
        }
        
        cout << totalBribes << endl;
    }
    
    return 0;
}
