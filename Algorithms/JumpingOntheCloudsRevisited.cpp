//
//  JumpingOntheCloudsRevisited.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/08/16.
//
//  https://www.hackerrank.com/challenges/jumping-on-the-clouds-revisited

#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    //n is the number of clouds.
    //k is the jump distance.
    int n, k;
    
    //Read parameters.
    cin >> n >> k;
    
    //Get clouds.
    vector<int> c(n);
    
    for(int c_i = 0; c_i < n; c_i++) {
        
        cin >> c[c_i];
    }

    //This is the first jump;
    int currentCloud = 0;
    int energy = 100;
    bool win = false;
    
    while(!win) {
     
        currentCloud = (currentCloud + k) % n;
        
        if(c[currentCloud] == 1) {
            
            //Thundercloud: two penalty decrease unit.
            energy -= 2;
        }
        
        //Standard decrease.
        energy -= 1;
        
        if(currentCloud == 0) {
            
            win = true;
        }
    }
    
    //Print energy.
    cout << energy;
    
    return 0;
}
