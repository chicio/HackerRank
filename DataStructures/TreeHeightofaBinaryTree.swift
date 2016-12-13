//
//  TreeHeightofaBinaryTree.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree

import Foundation

class Node {
    
    var data: Int
    var left: Node?
    var right: Node?
    
    init(d : Int) {
        
        data  = d
    }
}

class Tree {
    
    func insert(root: Node?, data: Int) -> Node? {
        
        if root == nil {
            
            return Node(d: data)
        }
        
        if data <= (root?.data)! {
            
            root?.left = insert(root: root?.left, data: data)
        } else {
            
            root?.right = insert(root: root?.right, data: data)
        }
        
        return root
    }
    
    /*!
     I just noted that i already solved
     this challenge in 30 days of code, but here I created
     a more elegant solution :).
     
     - param root: root node.
     
     - return the tree height.
     */
    func getHeight(root: Node?) -> Int {

        var countLeft = 0
        var countRight = 0
        
        if let left = root?.left {
            
            countLeft = 1 + getHeight(root: left)
        }

        if let right = root?.right {
            
            countRight = 1 + getHeight(root: right)
        }

        return countLeft > countRight ? countLeft : countRight
    }
}

var root: Node?
var tree = Tree()
var t = Int(readLine()!)!

while t > 0 {
    
    root = tree.insert(root: root, data: Int(readLine()!)!)
    t = t - 1
}

print(tree.getHeight(root: root))
