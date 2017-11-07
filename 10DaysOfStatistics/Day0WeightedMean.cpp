//
//  Day0WeightedMean.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 07.11.17.
//
//  https://www.hackerrank.com/challenges/s10-weighted-mean

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double calculateWeightedMeanFor(vector<int>& numbers, vector<int>& weights) {
    int weightedSum = 0;
    int weightSum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        weightedSum += numbers[i] * weights[i];
        weightSum += weights[i];
    }
    return ((double)weightedSum/(double)weightSum);
}

int main() {
    vector<int> numbers;
    vector<int> weights;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        numbers.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        cin >> k;
        weights.push_back(k);
    }
    cout << setprecision(1) << fixed << calculateWeightedMeanFor(numbers, weights) << endl;
    return 0;
}
