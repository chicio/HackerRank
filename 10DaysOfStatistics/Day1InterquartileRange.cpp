//
//  Day1InterquartileRange.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 07.11.17.
//
//  https://www.hackerrank.com/challenges/s10-interquartile-range

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

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
    vector<int> times;
    vector<int> numbersRepeatedTimes;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        numbers.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        cin >> k;
        times.push_back(k);
    }
    for (int i = 0; i < numbers.size(); i++) {
        for (int h = 0; h < times[i]; h++) {
            numbersRepeatedTimes.push_back(numbers[i]);
        }
    }
    int middlePosition = (int)numbersRepeatedTimes.size() / 2;
    sort(numbersRepeatedTimes.begin(), numbersRepeatedTimes.end());
    vector<int> firstPart(numbersRepeatedTimes.begin() + 0, numbersRepeatedTimes.begin() + middlePosition);
    vector<int> secondPart(numbersRepeatedTimes.begin() + (n % 2 != 0 ? middlePosition + 1 : middlePosition),
                           numbersRepeatedTimes.end());
    cout << setprecision(1) << fixed << calculateMedianFor(secondPart) - calculateMedianFor(firstPart) << endl;
    return 0;
}
