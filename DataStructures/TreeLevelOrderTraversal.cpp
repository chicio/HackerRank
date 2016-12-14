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
