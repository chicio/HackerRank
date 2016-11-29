//
//  DeleteDuplicateValueNodesFromaSortedLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 29/11/2016.
//
//  https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node* next;
};

Node* RemoveDuplicates(Node* head) {

    Node* currentNode = head;
    
    while (currentNode) {
        
        while (currentNode->next && currentNode->data == currentNode->next->data) {
            
            currentNode->next = currentNode->next->next;
        }
        
        currentNode = currentNode->next;
    }
    
    return head;
}
