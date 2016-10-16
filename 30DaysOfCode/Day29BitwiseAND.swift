//
//  Day29BitwiseAND.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 16/10/2016.
//
//  https://www.hackerrank.com/challenges/30-bitwise-and

import Foundation

var t = Int(readLine()!)!

for i in 0 ..< t {
    
    let currentTestCase:[Int] = readLine()!.characters.split(separator: " ",
                                                             maxSplits: Int.max,
                                                             omittingEmptySubsequences: true).map(String.init).map { Int($0)! }
    
    let n = currentTestCase[0]
    let k = currentTestCase[1]
    var max:Int = 0
    
    for j in  1 ... n {
        
        let lowerCheckBound = j + 1
        
        if lowerCheckBound <= n {
            
            for h in lowerCheckBound ... n {
                
                let andBitwise = j & h
                
                if andBitwise < k && andBitwise > max {
                    
                    max = andBitwise
                }
            }
        }
    }
    
    print(max)
}
