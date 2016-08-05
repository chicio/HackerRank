//
//  EqualStacks.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/07/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/equal-stacks

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
    
    //n1 is the number of elements in the first stack.
    //n2 is the number of elements in the second stack.
    //n3 is the number of elements in the third stack.
    int n1;
    int n2;
    int n3;
    
    //Vector that contains the three stacks.
    vector<vector<int>> stacks(3);
    vector<int> stacksSum(3);
    
    //Read parameters.
    cin >> n1 >> n2 >> n3;
    
    vector<int> h1(n1);
    stacksSum[0] = 0;
    
    for(int h1_i = n1 - 1; h1_i >= 0; h1_i--) {
        
        cin >> h1[h1_i];
        stacksSum[0] += h1[h1_i];
    }
    
    vector<int> h2(n2);
    stacksSum[1] = 0;
    
    for(int h2_i = n2 - 1; h2_i >= 0; h2_i--) {
        
        cin >> h2[h2_i];
        stacksSum[1] += h2[h2_i];
    }
    
    vector<int> h3(n3);
    stacksSum[2] = 0;
    
    for(int h3_i = n3 - 1; h3_i >= 0; h3_i--) {
        
        cin >> h3[h3_i];
        stacksSum[2] += h3[h3_i];
    }
    
    //Add stacks to list.
    stacks[0] = h1;
    stacks[1] = h2;
    stacks[2] = h3;
    
    int minHeight = min(min(stacksSum[0], stacksSum[1]), stacksSum[2]);
    
    while (minHeight > 0) {
        
        for (int k = 0; k < 3; k++) {
            
            //If current stack is not empty
            if(!stacks[k].empty() && stacksSum[k] != minHeight) {
                
                int lastElement = stacks[k].back();
                stacks[k].pop_back();
                stacksSum[k] -= lastElement;
            }
        }
        
        //Stop checking if we have the same height for all stacks.
        if(stacksSum[0] == stacksSum[1] && stacksSum[1] == stacksSum[2] && stacksSum[0] == stacksSum[2]) {
            
            break;
        }
        
        minHeight = min(min(stacksSum[0], stacksSum[1]), stacksSum[2]);
    }
    
    cout << minHeight;
    
    return 0;
}
