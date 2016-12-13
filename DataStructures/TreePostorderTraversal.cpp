//
//  TreePostorderTraversal.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-postorder-traversal

#include <iostream>

using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
};

void postOrder(node *root) {
    
    if (root->left) {
        
        postOrder(root->left);
    }
    
    if (root->right) {
        
        postOrder(root->right);
    }
    
    cout << root->data << " ";
}
