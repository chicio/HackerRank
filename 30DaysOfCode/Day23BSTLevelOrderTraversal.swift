//
//  Day23BSTLevelOrderTraversal.swift
//  HackerRank
//
//  Created by Fabrizio Duroni on 10/10/2016.
//
//  https://www.hackerrank.com/challenges/30-binary-trees

import Foundation

// Start of class Node
class Node {
    var data: Int
    var left: Node?
    var right: Node?
    
    init(d : Int) {
        data  = d
    }
} // End of class Node

// Start of class Tree
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
    
    /*
     Breadth first search visit method.
     
     @param root the current root level of the tree.
     */
    func levelOrder(root: Node?) {
        
        if let rootNode = root {
        
            var queue = [Node]()
            
            queue.append(rootNode)
            
            var current:Node
            
            while queue.isEmpty == false {
                
                current = queue.removeFirst()
                
                print("\(current.data)", separator: "", terminator: " ")
                
                if let leftSubtree = current.left {
                    
                    queue.append(leftSubtree)
                }
                
                if let rightSubtree = current.right {
                    
                    queue.append(rightSubtree)
                }
            }
        }
    } // End of function levelOrder
} // End of class Tree

var root: Node?
var tree = Tree()
var t = Int(readLine()!)!

while t > 0 {
    
    root = tree.insert(root: root, data: Int(readLine()!)!)
    t = t - 1
}

tree.levelOrder(root: root)
