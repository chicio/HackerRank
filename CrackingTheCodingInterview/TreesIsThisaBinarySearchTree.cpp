//
//  TreesIsThisaBinarySearchTree.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 05/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-is-binary-search-tree

#include <iostream>
#include <climits>

using namespace std;

/*!
 Binary search tree.
 */
class Node {
public:
    
    ///Left child.
    Node* left;
    ///Right child.
    Node* right;
    //Data.
    int data;
    
    Node(int value) {
        
        data = value;
    }
};

void insert(Node* node, int value) {
    
    if (value <= node->data) {
        
        if (node->left == nullptr) {
            
            node->left = new Node(value);
        } else {
            
            insert(node->left, value);
        }
    } else {
        
        if (node->right == nullptr) {
            
            node->right = new Node(value);
        } else {
            
            insert(node->right, value);
        }
    }
}

bool contains(Node* node, int value) {
    
    if (value == node->data) {
        
        return true;
    } else if (value < node->data) {
        
        if (node->left == nullptr) {
            
            return false;
        } else {
            
            return contains(node->left, value);
        }
    } else {
        
        if (node->right == nullptr) {
            
            return false;
        } else {
            
            return contains(node->right, value);
        }
    }
}

void inOrderTraversal(Node* node) {
    
    if (node->left != nullptr) {
        
        inOrderTraversal(node->left);
    }
    
    cout << node->data;
    
    if (node->right != nullptr) {
        
        inOrderTraversal(node->right);
    }
}

void preOrderTraversal(Node* node) {
    
    cout << node->data;
    
    if (node->left != nullptr) {
        
        inOrderTraversal(node);
    }
    
    if (node->right != nullptr) {
        
        inOrderTraversal(node);
    }
}

void postOrderTraversal(Node* node) {
    
    if (node->left != nullptr) {
        
        inOrderTraversal(node->left);
    }
    
    if (node->right != nullptr) {
        
        inOrderTraversal(node->right);
    }
    
    cout << node->data;
}

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
