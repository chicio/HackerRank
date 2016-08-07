//
//  StrangeCounter.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 06/08/16.
//
//  https://www.hackerrank.com/challenges/strange-code

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    
    //t is time value.
    unsigned long long t;
    
    //Read parameter.
    cin >> t;
    
    //Current start cycle time range.
    unsigned long long startCycleTimeRange = 1;
    //Updated start cycle time range.
    unsigned long long newStartCycleTimeRange = 0;
    //Flag used to check that we founded the starting position of the cycle range that contains t.
    bool foundCycleStartPosition = false;
    //Exponent for multiplier factor 2.
    unsigned long long exponent = 0;
    
    while (!foundCycleStartPosition) {
        
        newStartCycleTimeRange = startCycleTimeRange + (3 * pow(2, exponent));
        
        if(newStartCycleTimeRange > t) {
            
            //t is contained between startCycleTimeRange and newStartCycleTimeRange (exit loop).
            foundCycleStartPosition = true;
        } else {
            
            //Range not founde. Continue to search for it.
            startCycleTimeRange = newStartCycleTimeRange;
            exponent++;
        }
    }
    
    //Calculate cycle range.
    unsigned long long cycleRange = newStartCycleTimeRange - startCycleTimeRange;
    //Get value for t.
    unsigned long long value = cycleRange - (t - startCycleTimeRange);
    
    cout << value;
    
    return 0;
}
