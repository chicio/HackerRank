//
//  Day15LinkedList.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/10/2016.
//
//  https://www.hackerrank.com/challenges/30-linked-list

import Foundation

class Node {

    var data: Int
    var next: Node?
    
    init(data: Int) {
        self.data = data
        self.next = nil
    }
}

func insert(head: Node!, data: Int!) -> Node {

    if head == nil {
        
        return Node(data: data)
    }
    
    var lastNode = head.next
    
    while lastNode?.next != nil {
        
        lastNode = lastNode?.next
    }
    
    let newNode = Node(data: data)
    
    if let lastNodeFound = lastNode {
        
        lastNodeFound.next = newNode
    } else {
        
        head.next = newNode
    }
    
    return head
}

func display(head: Node!) {
    var current: Node! = head
    while current != nil {
        print(current.data, terminator: " ")
        current = current.next
    }
}

var head: Node! = nil
var n: Int = Int(readLine(strippingNewline: true)!)!

while n > 0 {
    
    let element = Int(readLine()!)
    head = insert(head: head, data: element)
    n = n - 1
}

display(head: head)
