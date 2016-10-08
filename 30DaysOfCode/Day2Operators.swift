//
//  Day2Operators.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/09/16.
//
//  https://www.hackerrank.com/challenges/30-operators

import Foundation

let mealCost:Float = Float(readLine()!)!
let tipPercent:Int = Int(readLine()!)!
let taxPercent:Int = Int(readLine()!)!

let tip:Float = mealCost * (Float(tipPercent)/100.0)
let tax:Float = mealCost * (Float(taxPercent)/100.0)
var totalCost = round(mealCost + tip + tax)

print("The total meal cost is \(Int(totalCost)) dollars.")
