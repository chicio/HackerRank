//
//  Day24MoreLinkedLists.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 11/10/2016.
//
//  https://www.hackerrank.com/challenges/30-linked-list-deletion

import Foundation

// Start of class Node
class Node {
    var data: Int
    var next: Node?
    
    init(d: Int) {
        data = d
    }
} // End of class Node

// Start of class LinkedList
class LinkedList {
    func insert(head: Node?, data: Int) -> Node? {
        if head == nil {
            return Node(d: data)
        }
        
        head?.next = insert(head: head?.next, data: data)
        
        return head
    }
    
    func display(head: Node?) {
        if head != nil {
            print(head!.data, terminator: " ")
            
            display(head: head?.next)
        }
    }
    
    // Start of function removeDuplicates
    func removeDuplicates(head: Node?) -> Node? {
        
        var currentRoot:Node? = head
        
        while currentRoot != nil {
            
            if let nextNode = currentRoot?.next {
                
                if nextNode.data == currentRoot!.data {
                    
                    if let nextNext = nextNode.next {
                        
                        currentRoot!.next = nextNext
                    } else {
                        
                        currentRoot!.next = nil
                    }
                } else {
                    
                    currentRoot = currentRoot!.next
                }
            } else {
                
                currentRoot = nil
            }
        }
        
        return head
    } // End of function removeDuplicates
} // End of class LinkedList

var head: Node?
var linkedList = LinkedList()

var t = Int(readLine()!)!

while t > 0 {
    
    head = linkedList.insert(head: head, data: Int(readLine()!)!)
    t = t - 1
}

linkedList.display(head: linkedList.removeDuplicates(head: head))
