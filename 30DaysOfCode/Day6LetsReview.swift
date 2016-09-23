//
//  Day6LetsReview.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 23/09/2016.
//
//  https://www.hackerrank.com/challenges/30-review-loop

import Foundation

let t:Int = Int(readLine()!)!
var s:String
var sEven:String
var sOdd:String

for i in 0 ..< t {

    s = readLine()!
    sEven = ""
    sOdd = ""
    
    for (i, c) in s.characters.enumerated() {
        
        if (i % 2 == 0) {
            
            sEven = sEven + String(c)
        } else {
            
            sOdd = sOdd + String(c)
        }
    }
    
    print(sEven + " " + sOdd)
}
