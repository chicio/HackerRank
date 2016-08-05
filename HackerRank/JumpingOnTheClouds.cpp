//
//  JumpingOnTheClouds.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 01/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/jumping-on-the-clouds

#include <vector>
#include <iostream>

using namespace std;

int main(){
    
    //n is the number of clouds.
    int n;
    
    //Read parameters.
    cin >> n;
    
    //Get clouds.
    vector<int> c(n);
    
    for(int c_i = 0; c_i < n; c_i++) {
        
        cin >> c[c_i];
    }
    
    //Number of jumps done (to be printed).
    int numberOfSteps = 0;
    
    //Flag used to check if the last cloud has be reached (game win).
    //NB: constraints says we can always win the game.
    bool win = false;
    
    //Current gamer cloud.
    int currentCloud = 0;
    
    while(!win) {
        
        currentCloud = (currentCloud + 2 < c.size() && c[currentCloud + 2] == 0 ? currentCloud + 2 : currentCloud +1);
        numberOfSteps++;
        win = (currentCloud == n - 1 ? true : false);
    }
    
    cout << numberOfSteps;
    
    return 0;
}
