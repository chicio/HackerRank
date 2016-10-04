//
//  Day17MoreExceptions.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 05/10/2016.
//
//  https://www.hackerrank.com/challenges/30-more-exceptions

import Darwin

// Defining enum for throwing error
// throw RangeError.NotInRange... is used to throw the error
enum RangeError : Error {
    case NotInRange(String)
}

// Start of class Calculator
class Calculator {
    
    // Start of function power
    func power(n: Int, p: Int) throws -> Int {

        guard n >= 0 && p >= 0 else {
            
            throw RangeError.NotInRange("n and p should be non-negative")
        }
        
        return Int(powf(Float(n), Float(p)))
    }
}

let myCalculator = Calculator()
var t = Int(readLine()!)!

while t > 0 {
    let np = readLine()!.characters.split(separator: " ",
                                          maxSplits: Int.max,
                                          omittingEmptySubsequences: true).map(String.init)
    
    do {
        let ans = try myCalculator.power(n: Int(np[0])!, p: Int(np[1])!)
        print(ans)
    } catch RangeError.NotInRange(let errorMsg) {
        print(errorMsg)
    }
    
    t = t - 1
}
