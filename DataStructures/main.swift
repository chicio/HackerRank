//
//  main.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/01/2017.
//  Copyright © 2017 Fabrizio Duroni. All rights reserved.
//

import Foundation

class Stack<T>: CustomStringConvertible {
    
    /// Stack array of element.
    private var stackArray:[T]
    /// Custom description.
    public var description:String {
        
        return stackArray.description
    }
    
    init() {
        
        //Init stack array as empty array.
        self.stackArray = [T]()
    }
    
    /**
     Push an element on the stack.
     
     - param newElement the new element to be placed on the stack.
     */
    func push(newElement: T) {
        
        self.stackArray.append(newElement)
    }
    
    /**
     Return top element of the stack and remove it.
     
     - returns the element on the top of the stack.
     */
    func pop() -> T {
        
        return self.stackArray.removeLast()
    }
    
    /**
     Check if the stack is empty
     
     - returns true if the stack is empty, else false.
     */
    func isEmpty() -> Bool {
        
        return self.stackArray.isEmpty
    }
    
    /**
     Return current top element of the stack, if there's one.
     */
    func peek() -> T? {
        
        return self.stackArray.last
    }
}

var numberOfBuildings = Int(readLine()!)!
var buildingsHeight:[Int] = readLine()!.characters.split(separator: " ",
                                                         maxSplits: Int.max,
                                                         omittingEmptySubsequences: true).map(String.init).map {
                                                            Int($0)!
                                                         }

//Here i needed some help :) http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
//Init stack of buildings.
var stackBuildings: Stack<Int> = Stack<Int>()

var maxArea = 0
var stackTop = 0
var areaWithStackTop = 0
var i = 0

while i < numberOfBuildings {
    
    if stackBuildings.isEmpty() || buildingsHeight[stackBuildings.peek()!] <= buildingsHeight[i] {
        
        stackBuildings.push(newElement: i)
        i = i + 1
    } else {
        
        stackTop = stackBuildings.pop()
        
        if let peek = stackBuildings.peek() {
            
            areaWithStackTop = buildingsHeight[stackTop] * (i - peek - 1)
        } else {
            
            areaWithStackTop = buildingsHeight[stackTop] * (i)
        }
        
        if maxArea < areaWithStackTop {
            
            maxArea = areaWithStackTop
        }
    }
}

while !stackBuildings.isEmpty() {
    
    stackTop = stackBuildings.pop()
    
    if let peek = stackBuildings.peek() {
        
        areaWithStackTop = buildingsHeight[stackTop] * (numberOfBuildings - peek - 1)
    } else {
        
        areaWithStackTop = buildingsHeight[stackTop] * (numberOfBuildings)
    }
    
    if maxArea < areaWithStackTop {
        
        maxArea = areaWithStackTop
    }
}

print(maxArea)


