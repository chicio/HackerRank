//
//  IsThisaBinarySearchTree.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 22/12/2016.
//
//  https://www.hackerrank.com/challenges/is-binary-search-tree

#include <climits>

struct Node {

    int data;
    Node* left;
    Node* right;
};

bool checkNode(Node *node, int min, int max) {
    
    if (node == nullptr) {
        
        return true;
    }
    
    if (node->data <= min || node->data >= max) {
        
        return false;
    }
    
    return checkNode(node->left, min, node->data) && checkNode(node->right, node->data, max);
}

/*!
 Check if a binary tree is a binary search tree.
 
 @param root root of the tree.
 */
bool checkBST(Node* root) {
    
    return checkNode(root, INT_MIN, INT_MAX);
}

