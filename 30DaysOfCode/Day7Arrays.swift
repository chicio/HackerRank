//
//  Day7Arrays.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 24/09/2016.
//
//  https://www.hackerrank.com/challenges/30-arrays

import Foundation

var n:Int = Int(readLine()!)!
var arr:[String] = readLine()!.characters.split(separator: " ",
                                                maxSplits: Int.max,
                                                omittingEmptySubsequences: true).map(String.init)

for i in (0 ..< n).reversed() {
    
    print(arr[i], separator: "", terminator: " ")
}
