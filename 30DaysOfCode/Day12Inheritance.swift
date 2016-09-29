//
//  Day12Inheritance.swift
//  HackerRank
//
//  Created by Duroni Fabrizio on 29/09/2016.
//
//  https://www.hackerrank.com/challenges/30-inheritance

import Foundation

class Person {
    
    var firstName: String
    var lastName: String
    var id: Int
    
    init(firstName: String, lastName: String, identification: Int) {
        
        self.firstName = firstName
        self.lastName = lastName
        self.id = identification
    }
    
    func printPerson() {
        
        print("Name: \(self.lastName), \(self.firstName)")
        print("ID: \(self.id)")
    }
}

class Student:Person {
    
    var testScores:[Int]
    
    init(firstName:String, lastName:String, identification:Int, scores:[Int]) {

        //Init scores.
        testScores = scores

        //Super init.
        super.init(firstName: firstName, lastName: lastName, identification: identification)
    }
    
    func calculate() -> String {
        
        var sum:Int = 0
        var average:Int = 0
        
        for score in testScores {
            
            sum = sum + score
        }
        
        if testScores.count > 0 {

            average = sum / testScores.count
        }
        
        var grade:String
        
        switch average {
        case 0 ... 39:
            grade = "T"
        case 40 ... 54:
            grade = "D"
        case 55 ... 69:
            grade = "P"
        case 70 ... 79:
            grade = "A"
        case 80 ... 89:
            grade = "E"
        case 90 ... 100:
            grade = "O"
        default:
            grade = "T"
        }
        
        return grade
    }
}

let nameAndID = readLine()!.characters.split(separator: " ",
                                             maxSplits: Int.max,
                                             omittingEmptySubsequences: true).map{String($0)}
let scoreCount = readLine()
let scores = readLine()!.characters.split(separator: " ",
                                          maxSplits: Int.max,
                                          omittingEmptySubsequences: true).map{Int(String($0))!}

let s = Student(firstName: nameAndID[0], lastName: nameAndID[1], identification: Int(nameAndID[2])!, scores: scores)

s.printPerson()

print("Grade: \(s.calculate())")
