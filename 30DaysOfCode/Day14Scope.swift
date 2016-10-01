//
//  Day14Scope.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 01/10/2016.
//
//  https://www.hackerrank.com/challenges/30-scope

import Foundation

class Difference {
  
    private var elements = [Int]()
    var maximumDifference : Int!
    
    init(a:[Int]) {
        
        elements = a
        //Could be init to zero, as range of elements is 1 ... 10
        maximumDifference = 0
    }

    func computeDifference() -> Void {
        
        //Could be init to zero, as range of elements is 1 ... 10
        var currentDifference:Int = 0
        
        for element1 in elements {
            
            for element2 in elements {
                
                currentDifference = abs(element1 - element2)
                
                if currentDifference > maximumDifference {
                    
                    maximumDifference = currentDifference
                }
            }
        }
    }
}

let n = Int(readLine()!)!
let a = readLine()!.characters.split(separator: " ",
                                     maxSplits: Int.max,
                                     omittingEmptySubsequences: true).map(String.init).map { Int($0)! }

let d = Difference(a: a)

d.computeDifference()

print(d.maximumDifference)
