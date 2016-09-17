//
//  PlusMinus.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/plus-minus

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    int positives = 0;
    int negatives = 0;
    int zeros = 0;
    
    int current_value;
    
    for(int i = 0; i < n; i++){
        
        cin >> current_value;
        
        //Add to the right set.
        if(current_value > 0) {
            
            positives++;
        } else if(current_value < 0) {
            
            negatives++;
        } else {
            
            zeros++;
        }
    }
    
    //Set precision output.
    cout << fixed;
    
    //Cast integers to get decimals.
    cout << setprecision(6) << ((float)positives / (float)n) << endl;
    cout << setprecision(6) << ((float)negatives / (float)n) << endl;
    cout << setprecision(6) << ((float)zeros / (float)n) << endl;
    
    return 0;
}
