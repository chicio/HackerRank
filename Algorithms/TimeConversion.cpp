//
//  TimeConversion.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/time-conversion

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    string time;
    cin >> time;
    
    string daySection = time.substr(8,2);
    string militaryTime;
    
    int hour = stoi(time.substr(0,2));
    
    if(daySection == "PM") {
        
        if(hour < 12) {
            
            cout << hour + 12 << time.substr(2, 6);
        } else {
            
            cout << time.substr(0, 8);
        }
    } else {
        
        if(hour < 12) {
            
            cout << time.substr(0, 8);
        } else {
            
            cout << "00" << time.substr(2, 6);
        }
    }
    
    return 0;
}
