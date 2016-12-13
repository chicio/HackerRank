//
//  FindMergePointofTwoLists.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/12/2016.
//
//  https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists

#include <set>

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

bool isMergeNode(set<Node*>& nodesExaminated, Node** nodeToBeChecked, int& data) {
    
    if (nodeToBeChecked) {
        
        if (nodesExaminated.find(*nodeToBeChecked) != nodesExaminated.end()) {
            
            data = (*nodeToBeChecked)->data;
            
            return true;
        } else {
            
            nodesExaminated.insert(*nodeToBeChecked);
        }
    }
    
    if ((*nodeToBeChecked)->next) {
        
        *nodeToBeChecked = (*nodeToBeChecked)->next;
    }
    
    return false;
}

int FindMergeNode(Node *headA, Node *headB) {

    set<Node*> nodesExaminated;
    
    Node* currentNodeA = headA;
    Node* currentNodeB = headB;
    int dataToBeReturned;
    
    while (true) {
        
        if (isMergeNode(nodesExaminated, &currentNodeA, dataToBeReturned)) {
            
            return dataToBeReturned;
        }
        
        if (isMergeNode(nodesExaminated, &currentNodeB, dataToBeReturned)) {
            
            return dataToBeReturned;
        }
    }
}
