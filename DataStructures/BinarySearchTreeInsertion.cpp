//
//  BinarySearchTreeInsertion.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 14/12/2016.
//
//  https://www.hackerrank.com/challenges/binary-search-tree-insertion


typedef struct node {

    int data;
    node* left;
    node* right;
} node;

node* insert(node* root, int value) {
    
    if (root == nullptr) {
        
        root = new node();
        root->data = value;
        
        return root;
    }
    
    if (value < root->data) {
        
        root->left = insert(root->left, value);
    } else {

        root->right = insert(root->right, value);
    }
    
    return root;
}
