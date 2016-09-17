//
//  CountingSort3.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/countingsort3

#include <vector>
#include <iostream>

using namespace std;

/*
 Counting sort modified to print out 
 a "strange" array of apperance counting.
 
 @param arr vector to be sorted.
 */
void countingSort(vector<int>& arr) {
    
    int min = arr[0];
    int max = arr[0];
    
    for (int i = 0; i < (int)arr.size(); i++) {
        
        if (arr[i] > max) {
            
            max = arr[i];
        }
        
        if (arr[i] < min) {
            
            min = arr[i];
        }
    }
    
    //Frequencies vector.
    vector<int> c(max - min + 1, 0);
    
    for (int i = 0; i < (int)arr.size(); i++) {
        
        c[arr[i] - min]++;
    }
    
    int k = 0;
    int apperance = 0;
    
    for (int i = 0; i < (int)c.size(); i++) {
        
        while (c[i] > 0) {
            
            arr[k] = i + min;
            k = k + 1;
            c[i]--;
            
            apperance++;
        }
        
        cout << apperance << " ";
    }
    
    if(c.size() < 99) {
        
        for (int i = (int)c.size(); i <= 99; i++) {

            cout << apperance << " ";
        }
    }
    
}

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    vector<string> arrString(n);
    
    for (int i = 0; i < n; ++i) {
        
        cin >> arr[i] >> arrString[i];
    }
    
    countingSort(arr);
        
    return 0;
}
