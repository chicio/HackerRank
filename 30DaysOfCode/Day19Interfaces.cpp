//
//  Day19Interfaces.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/10/2016.
//
//  https://www.hackerrank.com/challenges/30-interfaces

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class AdvancedArithmetic {
public:

    virtual int divisorSum(int n)=0;
};

class Calculator : public AdvancedArithmetic {
    
    int divisorSum(int n) {
        
        int divSum = 0;
        
        for (int i = 1; i <= n; i++) {
            
            if (n % i == 0) {
                
                divSum += i;
            }
        }
        
        return divSum;
    }
};

int main(){
    
    int n;

    cin >> n;
    
    AdvancedArithmetic *myCalculator = new Calculator();
    
    int sum = myCalculator->divisorSum(n);
    
    cout << "I implemented: AdvancedArithmetic\n" << sum;
   
    return 0;
}
