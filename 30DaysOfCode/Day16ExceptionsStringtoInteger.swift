//
//  Day16ExceptionsStringtoInteger.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 03/10/2016.
//
//  https://www.hackerrank.com/challenges/30-exceptions-string-to-integer

import Foundation

/*
 * Define an ErrorType
 */
enum StringToIntTypecastingError: Error {
    case BadString
}

/*
 * If typecasting is not possible, throw exception, otherwise return the Integer value
 */
func stringToInt(inputString: String) throws -> Int {
    
    let integerValue = Int(inputString)
    
    guard integerValue != nil else {
        
        throw StringToIntTypecastingError.BadString
    }
    
    return integerValue!
}

/*
 * Read the input
 */
let inputString = readLine()!

do {
    
    print(try stringToInt(inputString: inputString))
} catch StringToIntTypecastingError.BadString {
    
    print("Bad String")
}
