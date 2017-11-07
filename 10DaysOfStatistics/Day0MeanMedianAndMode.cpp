//
//  Day0MeanMedianAndMode.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06.11.17.
//
//  https://www.hackerrank.com/challenges/s10-basic-statistics

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

double calculateModaFor(vector<int>& numbers) {
    int currentElementWithMaxOccurrences = 0;
    int currentMaxOccurrences = 0;
    int occurrences = 0;
    int previousElement = 0;
    for (int number: numbers) {
        if (number == previousElement) {
            occurrences++;
        } else {
            if (occurrences > currentMaxOccurrences) {
                currentElementWithMaxOccurrences = previousElement;
                currentMaxOccurrences = occurrences;
            }
            occurrences = 1;
        }
        previousElement = number;
    }
    return currentElementWithMaxOccurrences;
}

int main() {
    vector<int> numbers;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        numbers.push_back(k);
    }
    sort(numbers.begin(), numbers.end());
    cout << calculateMeanFor(numbers) << endl;
    cout << calculateMedianFor(numbers) << endl;
    cout << calculateModaFor(numbers) << endl;
    return 0;
}
