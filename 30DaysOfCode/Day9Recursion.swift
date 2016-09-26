//
//  Day9Recursion.swift
//  HackerRank
//
//  Created by Duroni Fabrizio on 26/09/2016.
//
//  https://www.hackerrank.com/challenges/30-recursion

import Foundation

func factorial(n:Int) -> Int {

    if n == 0 {
        
        return 1
    }
    
    return n * factorial(n: n - 1)
}

var n:Int = Int(readLine()!)!

print(factorial(n: n))
