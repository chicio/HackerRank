//
//  DiagonalDifference.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/diagonal-difference

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int dimension;
    cin >> dimension;
    
    vector< vector<int> > a(dimension,vector<int>(dimension));
    
    for(int a_i = 0; a_i < dimension; a_i++){
        for(int a_j = 0; a_j < dimension; a_j++){
            cin >> a[a_i][a_j];
        }
    }
    
    int diagonal_sum_left = 0;
    for(int current_dim = 0; current_dim < dimension; current_dim++) {
        diagonal_sum_left += a[current_dim][current_dim];
    }
    
    int diagonal_sum_right = 0;
    int current_row = dimension;
    for(int current_dim = 0; current_dim < dimension; current_dim++) {
        diagonal_sum_right += a[--current_row][current_dim];
    }
    
    int sum = abs(diagonal_sum_left - diagonal_sum_right);
    
    cout << sum;
    
    return 0;
}
