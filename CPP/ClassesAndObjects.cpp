//
//  ClassesAndObjects.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/classes-objects

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Student {
    
    int scores[5];
    
public:
    
    void input() {
        
        for(int i = 0; i < 5; i++) {
            
            cin >> scores[i];
        }
    }
    
    int calculateTotalScore() {
        
        int totalScore = 0;
        
        for(int i = 0; i < 5; i++) {
            
            totalScore += scores[i];
        }
        
        return totalScore;
    }
};

int main() {
    
    int n; // number of students
    cin >> n;
    
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }
    
    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();
    
    // determine how many students scored higher than kristen
    int count = 0;
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }
    
    // print result
    cout << count;
    
    return 0;
}
