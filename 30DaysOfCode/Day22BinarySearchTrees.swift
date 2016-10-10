//
//  Day22BinarySearchTrees.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 09/10/2016.
//
//  https://www.hackerrank.com/challenges/30-binary-search-trees

import Foundation

// Start of Node class
class Node {
    var data: Int
    var left: Node?
    var right: Node?
    
    init(d : Int) {
        data  = d
    }
} // End of Node class

// Start of Tree class
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
    
    func getHeight(root: Node?) -> Int {

        if let rootNode = root {
            
            let left:Int = getHeight(root: rootNode.left)
            let right:Int = getHeight(root: rootNode.right)
            
            if left > right {
                
                return left + 1
            } else {
                
                return right + 1
            }
            
        } else {
            
            return -1
        }
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
