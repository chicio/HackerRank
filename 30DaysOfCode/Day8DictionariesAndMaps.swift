//
//  Day8DictionariesAndMaps.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 25/09/2016.
//
//  https://www.hackerrank.com/challenges/30-dictionaries-and-maps

import Foundation

var n:Int = Int(readLine()!)!
var phoneBook:[String:String] = [String:String]()
var currentLine:[String]

for i in (0 ..< n) {
    
    //Add row to phone book.
    currentLine = readLine()!.characters.split(separator: " ",
                                               maxSplits: Int.max,
                                               omittingEmptySubsequences: true).map(String.init)
    
    phoneBook[currentLine[0]] = currentLine[1]
}

while true {
    
    if let currentPersoneName = readLine() {
        
        //Unwrap phone number.
        if let currentPhoneNumber = phoneBook[currentPersoneName] {
            
            print("\(currentPersoneName)=\(currentPhoneNumber)")
        } else {
            
            print("Not found")
        }
    } else {
        
        break
    }
}
