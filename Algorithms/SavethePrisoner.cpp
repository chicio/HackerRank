//
//  SavethePrisoner.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 06/08/16.
//
//  https://www.hackerrank.com/challenges/save-the-prisoner

#include <iostream>

using namespace std;

int main() {
    
    //t is the number of test cases.
    //n is the number of prisoners.
    //m is the number of sweets.
    //s is the prisoner ID.
    int t, n, m, s;
    
    //Read parameter.
    cin >> t;
    
    int position, prisonerPoisonRisk;
    
    for (int i = 0; i < t; i++) {
        
        //Read test case data.
        cin >> n >> m >> s;
        
        //Must check position n that gives 0 with modulo operation (good test case :)).
        position = (s + m - 1) % n;
        prisonerPoisonRisk = position == 0 ? n : position;
        
        cout << prisonerPoisonRisk << endl;
    }
    
    return 0;
}
