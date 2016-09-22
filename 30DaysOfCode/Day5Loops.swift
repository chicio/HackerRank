//
//  Day5Loops.swift
//  HackerRank
//
//  Created by Duroni Fabrizio on 22/09/2016.
//
//  https://www.hackerrank.com/challenges/30-loops

import Foundation

let n:Int = Int(readLine()!)!
var result:Int

for i in 1 ... 10 {
    
    result = n * i
    print("\(n) x \(i) = \(result)")
}
