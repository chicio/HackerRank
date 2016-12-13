//
//  TreePreorderTraversal.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-preorder-traversal

#include <iostream>

using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
};

void preOrder(node *root) {
    
    cout << root->data << " ";
    
    if (root->left) {
    
        preOrder(root->left);
    }
    
    if (root->right) {
        
        preOrder(root->right);
    }
}
