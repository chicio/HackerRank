//
//  DequeSTL.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 25/08/16.
//
//  https://www.hackerrank.com/challenges/deque-stl

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

/**
 I must admit I was not able to solve this with dequeu.
 This is the first challenge in C++ section that I was not able to solve.
 I get "inspired" from this link http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/#disqus_thread"
 reported in the discussion tab.
 So I didn't solve this challenge, but I learned something new :) (and found geeksforgeeks.com, a wonderful site XD).
 */
void printKMax(int arr[], int n, int k) {
    
    deque<int> buffer;
    
    for (int i = 0; i < k; ++i) {
        
        // For very element, the previous smaller elements are useless so remove them from Qi.
        while((!buffer.empty()) && arr[i] >= arr[buffer.back()]) {
            
            buffer.pop_back();
        }
        
        // Add new element at rear of queue.
        buffer.push_back(i);
    }
    
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (int i = k; i < n; ++i) {
        
        // The element at the front of the queue is the largest element of
        // previous window, so print it.
        cout << arr[buffer.front()] << " ";
        
        // Remove the elements which are out of this window.
        while ((!buffer.empty()) && buffer.front() <= i - k) {
            
            buffer.pop_front();
        }
        
        while ((!buffer.empty()) && arr[i] >= arr[buffer.back()]) {

            buffer.pop_back();
        }
        
        // Add current element at the rear of Qi
        buffer.push_back(i);
    }
    
    cout << arr[buffer.front()] << " " << endl;
}

int main() {
    
    int t;
    
    cin >> t;
    
    while(t>0) {
        
        int n,k;
        
        cin >> n >> k;
        
        int i;
        int arr[n];
        
        for(i=0;i<n;i++) {
            
            cin >> arr[i];
        }
        
        printKMax(arr, n, k);
        
        t--;
    }
    
    return 0;
}
