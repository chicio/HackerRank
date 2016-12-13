//
//  TreeInorderTraversal.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-inorder-traversal

#include <iostream>

using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
};

void inOrder(node *root) {
    
    if (root->left) {
        
        inOrder(root->left);
    }
    
    cout << root->data << " ";
    
    if (root->right) {
        
        inOrder(root->right);
    }
}
