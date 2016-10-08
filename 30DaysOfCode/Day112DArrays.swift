//
//  Day112DArrays.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 28/09/2016.
//
//  https://www.hackerrank.com/challenges/30-2d-arrays

import Foundation

var arr:[[Int]] = [[Int]]()
var currentLine:[String]

for i in (0 ..< 6) {
    
    //Add row to list (matrix).
    currentLine = readLine()!.characters.split(separator: " ",
                                               maxSplits: Int.max,
                                               omittingEmptySubsequences: true).map(String.init)

    arr.append([Int]())
    
    for h in (0 ..< 6) {
        
        arr[i].append(Int(currentLine[h])!)
    }
}

var maxSum:Int = 0
var currentSum:Int = 0

for i in (0 ..< 4) {
    
    for k in (0 ..< 4) {
     
        //First hourglass row.
        currentSum = arr[i][k] + arr[i][k + 1] + arr[i][k + 2]
        
        //Second hourglass row.
        currentSum = currentSum + arr[i + 1][k + 1]
        
        //Third hourglass row.
        currentSum = currentSum + arr[i + 2][k]
        currentSum = currentSum + arr[i + 2][k + 1]
        currentSum = currentSum + arr[i + 2][k + 2]
        
        //Check current sum.
        if currentSum > maxSum || (i == 0 && k == 0) {
            
            maxSum = currentSum
        }
    }
}

print(maxSum)
