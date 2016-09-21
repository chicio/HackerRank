//
//  Day4ClassvsInstance.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/09/2016.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//

import Foundation

public class Person {
    
    private var age:Int
    
    init(initialAge initAge:Int) {
        
        if(initAge < 0) {

            age = 0
            print("Age is not valid, setting age to 0.")
        } else {

            age = initAge
        }
    }
    
    public func yearPasses() {
        
        age = age + 1
    }
    
    public func amIOld() {
        
        switch age {
        case 0 ... 12:
            print("You are young.")
        case 13 ... 17:
            print("You are a teenager.")
        default:
            print("You are old.")
        }
    }
    
}

var t = Int(readLine(strippingNewline: true)!)!

while t > 0 {
    
    let age = Int(readLine(strippingNewline: true)!)!
    var p = Person(initialAge: age)
    p.amIOld()
    
    for i in 1 ... 3 {
        p.yearPasses()
    }
    
    p.amIOld()
    print("")
    
    t = t - 1 // decrement t
}
