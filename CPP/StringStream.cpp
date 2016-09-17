//
//  StringStream.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/08/16.
//
//  https://www.hackerrank.com/challenges/c-tutorial-stringstream

#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
    
    stringstream ss(str);
    char ch;
    int a;
    
    vector<int> numbers;
    
    while(ss >> a) {
        
        numbers.push_back(a);
        ss >> ch;
    }
    
    return numbers;
}

int main() {
    
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    
    for(int i = 0; i < integers.size(); i++) {
        
        cout << integers[i] << "\n";
    }
    
    return 0;
}
