//
//  TreeHuffmanDecoding.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 14/12/2016.
//
//  https://www.hackerrank.com/challenges/tree-huffman-decoding

#include <string>
#include <iostream>

using namespace std;

typedef struct node {
    
    int freq;
    char data;
    node* left;
    node* right;
} node;

void decode_huff(node* root,string s) {
    
    string output = "";
    node* currentNode = root;
    
    for (char& currentChar : s) {
        
        if (currentChar == '0') {
            
            currentNode = currentNode->left;
        } else {
            
            currentNode = currentNode->right;
        }
        
        if (currentNode->data != '\0') {
            
            output = output + currentNode->data;
            currentNode = root;
        }
    }
    
    cout << output;
}
