//
//  InsertaNodeAtTheTailOfaLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 23/10/2016.
//
//  https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node *next;
};

Node* Insert(Node* head, int data) {

    //No head: create root node.
    if (head == nullptr) {
        
        head = new Node();
        head->data = data;
        
        return head;
    }
    
    //Search currentTailNode.
    Node* currentNode = head;
    
    while (currentNode->next != nullptr) {
        
        currentNode = currentNode->next;
    }
    
    //Create new node.
    Node *newTailNode = new Node();
    newTailNode->data = data;
    
    //Insert new tail.
    currentNode->next = newTailNode;
    
    return head;
}
