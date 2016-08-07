//
//  AngryProfessor.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 30/07/16.
//
//  https://www.hackerrank.com/challenges/angry-professor

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    //t is the number of test cases to be executed.
    int t;
    
    //Read parameters.
    cin >> t;
    
    //n is the number of students in the class.
    //k is the threshold for cancellation.
    int n;
    int k;
    int studentsOnTime = 0;
    
    for(int currentTestCase = 0; currentTestCase < t; currentTestCase++){
        
        //Read parameters.
        cin >> n >> k;
        vector<int> studentsArrivalTime(n);
        
        for(int currentStudent = 0; currentStudent < n; currentStudent++){
            
            //Read student arrival time.
            cin >> studentsArrivalTime[currentStudent];
            
            //Check timing.
            if(studentsArrivalTime[currentStudent] <= 0) {
             
                studentsOnTime++;
            }
        }
        
        cout << (studentsOnTime >= k ? "NO" : "YES");
    }
    
    return 0;
}
