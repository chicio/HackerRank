//
//  Day10BinaryNumbers.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 27/09/2016.
//
//  https://www.hackerrank.com/challenges/30-binary-numbers

import Foundation

var n:Int = Int(readLine()!)!
var b:String = ""

while n > 0 {
    
    var remainder = n % 2
    n = n / 2
    
    b = String(remainder) + b
}

var currentConsecutiveOnes:Int = 0
var lastConsecutiveOnes:Int = 0

for char in b.characters {
    
    if char == "1" {
        
        currentConsecutiveOnes = currentConsecutiveOnes + 1
    } else {
        
        currentConsecutiveOnes = 0
    }
    
    if(currentConsecutiveOnes > lastConsecutiveOnes) {
        
        lastConsecutiveOnes = currentConsecutiveOnes
    }
}

print(lastConsecutiveOnes)
