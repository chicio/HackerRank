//
//  Day18QueuesandStacks.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/10/2016.
//
//  https://www.hackerrank.com/challenges/30-queues-stacks

import Foundation

class Solution {
    
    var stack = [Character]()
    var queue = [Character]()

    func pushCharacter(ch: Character) -> Void {
    
        stack.append(ch)
    }
 
    func popCharacter() -> Character {

        return stack.removeLast()
    }

    func enqueueCharacter(ch: Character) -> Void {
        
        queue.append(ch)
    }
    
    func dequeueCharacter() -> Character {
        
        return queue.removeFirst()
    }
}

// read the string s.
let s = readLine()!

// create the Solution class object p.
let obj = Solution()

// push/enqueue all the characters of string s to stack.
for c in s.characters {
    
    obj.pushCharacter(ch: c)
    obj.enqueueCharacter(ch: c)
}

var isPalindrome = true

// pop the top character from stack.
// dequeue the first character from queue.
// compare both the characters.
for i in 0 ..< (s.characters.count / 2) {
    
    if obj.popCharacter() != obj.dequeueCharacter() {
        
        isPalindrome = false
        break
    }
}

// finally print whether string s is palindrome or not.
if isPalindrome {
    print("The word, \(s), is a palindrome.")
} else {
    print("The word, \(s), is not a palindrome.")
}
