//
//  Day21Generics.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 08/10/2016.
//  
//  https://www.hackerrank.com/challenges/30-generics

import Foundation

// Start of struct Printer
struct Printer<type> {

    func printArray(a:[type]) -> Void {
        
        for i in 0 ..< a.count {

            print(a[i])
        }
    }
}

let vInt = [1, 2, 3]
let vString = ["Hello", "World"]

Printer<Int>().printArray(vInt)
Printer<String>().printArray(vString)
