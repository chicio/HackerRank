//
//  File.swift
//  HackerRank
//
//  Created by Duroni Fabrizio on 20/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/30-conditional-statements

import Foundation

let n:Int = Int(readLine()!)!

if (n % 2 != 0) {
    
    print("Weird")
} else if (n % 2 == 0) {

    switch(n) {
    case 2 ... 5:
        print("Not Weird")
    case 6 ... 20:
        print("Weird")
    case let x where x > 20:
        print("Not Weird")
    default:
        print("")
    }
}
