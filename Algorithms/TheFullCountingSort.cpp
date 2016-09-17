//
//  TheFullCountingSort.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/09/16.
//
//  https://www.hackerrank.com/challenges/countingsort4

#include <vector>
#include <iostream>

using namespace std;

template <typename T> void printVector(vector<T> ar, int min, int max) {
    
    for (int i = min; i <= max; i++) {
        
        cout << ar[i] << " ";
    }
    
    cout << endl;
}

/*!
 Counting sort modified to print two correlated arrays.
 
 @param arr vector to be sorted.
 */
void countingSort(vector<int>& arr, vector<string>& arrString) {
    
    int min = arr[0];
    int max = arr[0];
    
    vector<int> originalArr = arr;
    
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
    
    for (int i = 0; i < (int)c.size(); i++) {
        
        int currentElementOccurrence = 0;
        int currentPos = 0;
        
        while (currentElementOccurrence < c[i]) {

            if(originalArr[currentPos] == i + min) {

                cout << arrString[currentPos] << " ";
                currentElementOccurrence++;
            }
            
            currentPos++;
        }
    }
}

int main() {
    
    int n;
    
    cin >> n;
    
    vector<int> arr(n);
    vector<string> arrString(n);

    for (int i = 0; i < n; i++) {
        
        cin >> arr[i] >> arrString[i];
        
        if(i < (n / 2)) {
            
            arrString[i] = "-";
        }
    }
    
    countingSort(arr, arrString);
    
    return 0;
}
