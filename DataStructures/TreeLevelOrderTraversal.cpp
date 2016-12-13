//
//  TreeLevelOrderTraversal.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 14/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-level-order-traversal

#include <queue>
#include <iostream>

using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
};

/*
 Breadth first search visit method.
 
 @param root the current root level of the tree.
 */
void LevelOrder(node * root) {
    
    queue<node*> q;
    
    q.push(root);
    
    node* currentNode;
    
    while (!q.empty()) {
        
        currentNode = q.front();
        q.pop();
        
        cout << currentNode->data << " ";
        
        if (currentNode->left) {
            
            q.push(currentNode->left);
        }
        
        if (currentNode->right) {
            
            q.push(currentNode->right);
        }
    }
}

///*
// Breadth first search visit method.
// 
// @param root the current root level of the tree.
// */
//func levelOrder(root: Node?) {
//    
//    if let rootNode = root {
//        
//        var queue = [Node]()
//        
//        queue.append(rootNode)
//        
//        var current:Node
//        
//        while queue.isEmpty == false {
//            
//            current = queue.removeFirst()
//            
//            print("\(current.data)", separator: "", terminator: " ")
//            
//            if let leftSubtree = current.left {
//                
//                queue.append(leftSubtree)
//            }
//            
//            if let rightSubtree = current.right {
//                
//                queue.append(rightSubtree)
//            }
//        }
//    }
//} // End of function levelOrder
