//
//  BinarySearchTreeLowestCommonAncestor.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 15/12/2016.
//
//  https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor

typedef struct node {
    
    int data;
    node* left;
    node* right;
} node;

node* lca(node* root, int v1,int v2) {
    
    if (root->data > v1 && root->data > v2) {
        
        return lca(root->left, v1, v2);
    }
    
    if (root->data < v1 && root->data < v2) {
        
        return lca(root->right, v1, v2);
    }
    
    return root;
}
