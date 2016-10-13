//
//  Day26NestedLogic.swift
//  HackerRank
//
//  Created by Duroni Fabrizio on 13/10/2016.
//
//  https://www.hackerrank.com/challenges/30-nested-logic

import Foundation

func calculateFine(actualDate:[Int], expectedDate:[Int]) -> Int {
    
    var fine:Int = 0
    
    if actualDate[2] <= expectedDate[2] {
        
        if actualDate[1] <= expectedDate[1] {
            
            if actualDate[0] > expectedDate[0] {
                
                //Late day.
                fine = 15 * (actualDate[0] - expectedDate[0])
            }
        } else {
            
            //Late month.
            fine = 500 * (actualDate[1] - expectedDate[1])
        }
    } else {
        
        //Late year.
        fine = 10000
    }
    
    return fine
}

var actualDate:[Int] = readLine()!.characters.split(separator: " ",
                                                    maxSplits: Int.max,
                                    omittingEmptySubsequences: true).map(String.init).map { Int($0)! }

var expectedDate:[Int] = readLine()!.characters.split(separator: " ",
                                                      maxSplits: Int.max,
                                      omittingEmptySubsequences: true).map(String.init).map { Int($0)! }


let fine:Int = calculateFine(actualDate: actualDate, expectedDate: expectedDate)





