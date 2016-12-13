//
//  ReverseADoublyLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 09/12/2016.
//
//  https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list

struct Node {
    
    int data;
    Node* next;
    Node* prev;
};

Node* Reverse(Node* head) {

    if (head == nullptr) {
        
        return head;
    }
    
    Node* currentNode = head;
    Node* temp = nullptr;
    
    while (currentNode) {
        
        temp = currentNode->prev;
        currentNode->prev = currentNode->next;
        currentNode->next = temp;
        currentNode = currentNode->prev;
    }
    
    if (temp) {
        
        head = temp->prev;
    }
    
    return head;
}




