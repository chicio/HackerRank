//
//  GetNodeValue.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 29/11/2016.
//
//  https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail

#include <vector>

using namespace std;

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node* next;
};

int GetNode(Node* head,int positionFromTail) {

    vector<Node*> positions;
    Node* currentNode = head;
    
    while (currentNode) {
        
        positions.push_back(currentNode);
        currentNode = currentNode->next;
    }
    
    return positions[positions.size() - positionFromTail - 1]->data;
}
