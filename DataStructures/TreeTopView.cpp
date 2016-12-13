//
//  TreeTopView.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-top-view

#include <iostream>

using namespace std;

struct node {
    
    int data;
    node* left;
    node* right;
};

void printLeft(node* root) {
    
    if (root->left) {
        
        printLeft(root->left);
    }
    
    cout << root->data << " ";
}

void printRight(node* root) {
    
    cout << root->data << " ";
    
    if (root->right) {
        
        printRight(root->right);
    }
}

void top_view(node* root) {
    
    printLeft(root->left);
    cout << root->data << " ";
    printRight(root->right);
}
