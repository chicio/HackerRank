//
//  Day1StandardDeviation.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 08.11.17.
//
//  https://www.hackerrank.com/challenges/s10-standard-deviation/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double calculateMeanFor(vector<int>& numbers) {
    int sum = 0;
    for (int number: numbers) {
        sum += number;
    }
    return ((double)sum/(double)numbers.size());
}

double calculateSquaredDistanceFor(vector<int>& numbers, double mean) {
    double squaredDistance = 0;
    for (int number: numbers) {
        squaredDistance += pow(number - mean, 2.0);
    }
    return squaredDistance;
}

double calculateStandardDeviationFor(vector<int>& numbers, double mean) {
    double squaredDistance = calculateSquaredDistanceFor(numbers, mean);
    double standardDeviation = sqrt(squaredDistance / numbers.size());
    return standardDeviation;
}

int main() {
    vector<int> numbers;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        numbers.push_back(k);
    }
    cout << setprecision(1) << fixed << calculateStandardDeviationFor(numbers, calculateMeanFor(numbers));
    return 0;
}
