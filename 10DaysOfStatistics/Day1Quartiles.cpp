//
//  Day1Quartiles.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 07.11.17.
//
//  https://www.hackerrank.com/challenges/s10-quartiles

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

double calculateMedianFor(vector<int>& numbers) {
    double median;
    size_t size = numbers.size();
    if (numbers.size() % 2 == 0) {
        median = (double)(numbers[size / 2 - 1] + numbers[size / 2]) / 2;
    } else {
        median = numbers[numbers.size() / 2];
    }
    return median;
}

int main() {
    vector<int> numbers;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        numbers.push_back(k);
    }
    int middlePosition = n / 2;
    sort(numbers.begin(), numbers.end());
    vector<int> firstPart(numbers.begin() + 0, numbers.begin() + middlePosition);
    vector<int> secondPart(numbers.begin() + (n % 2 != 0 ? middlePosition + 1 : middlePosition), numbers.end());
    cout << calculateMedianFor(firstPart) << endl;
    cout << calculateMedianFor(numbers) << endl;
    cout << calculateMedianFor(secondPart) << endl;
    return 0;
}
