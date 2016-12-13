//
//  InsertingaNodeIntoaSortedDoublyLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/12/2016.
//
//  https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list

struct Node {
    
    int data;
    Node *next;
    Node *prev;
};

Node* SortedInsert(Node *head,int data) {
    
    Node* newNode = new Node();
    newNode->data = data;
    
    if (head == nullptr) {
        
        head = newNode;
        return head;
    }
    
    Node* oldNode = newNode;
    newNode->next = head;
    head = newNode;
    
    while (newNode != nullptr) {
        
        oldNode = newNode;
        newNode = newNode->next;
        
        if(newNode != nullptr) {
            
            if(oldNode->data > newNode->data) {
                
                int oldData = oldNode->data;
                oldNode->data = newNode->data;
                newNode->data = oldData;
            }
        }
    }
    
    return head;
}
