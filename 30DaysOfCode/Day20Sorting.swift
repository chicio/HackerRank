//
//  Day20Sorting.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 07/10/2016.
//
//  https://www.hackerrank.com/challenges/30-sorting

import Foundation

/*!
 Bubble sort swift implementation.
 
 @param a array to be sorted (inout).
 @param totalSwaps number of swaps executed (inout).
 */
func bubbleSort(a:inout [Int], totalSwaps: inout Int) -> Void {
    
    for _ in 0 ..< a.count {
        
        var numberOfSwaps:Int = 0;
        
        for j in 0 ..< (a.count - 1) {

            if a[j] > a[j + 1] {
                
                swap(&a[j], &a[j + 1]);
                numberOfSwaps = numberOfSwaps + 1;
            }
        }
        
        if numberOfSwaps == 0 {
            
            break;
        }
        
        totalSwaps = totalSwaps + numberOfSwaps
    }
}

let n = Int(readLine()!)!
var a = readLine()!.characters.split(separator: " ",
                                     maxSplits: Int.max,
                                     omittingEmptySubsequences: true).map(String.init).map { Int($0)! }
var totalSwaps:Int = 0

bubbleSort(a: &a, totalSwaps: &totalSwaps)

print("Array is sorted in \(totalSwaps) swaps.")
print("First Element: \(a[0])")
print("Last Element: \(a[a.count - 1])")
