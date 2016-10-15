//
//  Day28RegExPatternsandIntrotoDatabases.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 15/10/2016.
//
//  https://www.hackerrank.com/challenges/30-regex-patterns

import Foundation

var n = Int(readLine()!)!
var gmailUserList:[[String]] = [[String]]()

for _ in 0 ..< n {

    var row:[String] = readLine()!.characters.split(separator: " ",
                                                    maxSplits: Int.max,
                                                    omittingEmptySubsequences: true).map{ String($0) }
    
    let emailRegEx = "\\b([a-zA-Z0-9]+(@[a-zA-Z0-9]*gmail.com){1})\\b"
    let emailTest = NSPredicate(format: "SELF MATCHES %@", emailRegEx)
    
    if emailTest.evaluate(with: row[1]) {
        
        gmailUserList.append(row)
    }
}

gmailUserList.sort { $0[0] < $1[0] }

for currentPosition in 0 ..< gmailUserList.count {
    
    print(gmailUserList[currentPosition][0])
}
