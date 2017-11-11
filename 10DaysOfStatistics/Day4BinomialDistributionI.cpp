//
//  Day4BinomialDistributionI.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 11.11.17.
//
//  https://www.hackerrank.com/challenges/s10-binomial-distribution-1

#include <stdio.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <random>

using namespace std;

double factorial(double n) {
    if(n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

double combinations(double n, double r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

double binomialProbability(double x, double n, double p) {
    return combinations(n, x) * pow(p, x) * pow(1 - p, n - x);
}

int main() {
    double boysRatio = 1.09;
    double girlsRatio = 1;
    double n = 6;
    double p = boysRatio / (girlsRatio + boysRatio);
    double cumulativeProbability = 0;
    for (double x = 3; x <= 6; x++) {
        cumulativeProbability += binomialProbability(x, n, p);
    }
    cout << setprecision(3) << fixed << cumulativeProbability;
    return 0;
}
