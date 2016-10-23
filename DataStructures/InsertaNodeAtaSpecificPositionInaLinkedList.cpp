//
//  InsertaNodeAtaSpecificPositionInaLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 23/10/2016.
//
//  https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node* next;
};

Node* InsertNth(Node* head, int data, int position) {
  
    //No head or position = 0: update head.
    if (position == 0 || head == nullptr) {
        
        Node* newHead = new Node();
        newHead->data = data;
        newHead->next = head;
        
        return newHead;
    }
    
    //Search node at position received as input.
    int currentPosition = 1;
    Node* currentNode = head;
    
    while (currentPosition != position) {
        
        currentNode = currentNode->next;
        currentPosition++;
    }
    
    //Create new node.
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = currentNode->next;
    
    //Update next of current node.
    currentNode->next = newNode;
    
    return head;
}
