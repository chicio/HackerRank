//
//  Day25RunningTimeandComplexity.swift
//  HackerRank
//
//  Created by Duroni Fabrizio on 12/10/2016.
//
//  https://www.hackerrank.com/challenges/30-running-time-and-complexity

import Foundation

var n = Int(readLine()!)!

/*!
 Testing primality using trial division method.
 
 @see https://en.wikipedia.org/wiki/Trial_division
 
 @param number the number to be tested.
 
 @returns true if number is a prime, else false.
 */
func isPrime(number:Int) -> Bool {
    
    if number <= 1 {
        
        return false
    }
    
    if number == 2 {
        
        return true
    }
    
    for i in 2 ... Int(sqrt(Double(number))) {
        
        if number % i == 0 {
            
            return false
        }
    }
    
    return true
}

for _ in 0 ..< n  {
    
    let t = Int(readLine()!)!
    
    if isPrime(number: t) {
        
        print("Prime")
    } else {
        
        print("Not prime")
    }
}
