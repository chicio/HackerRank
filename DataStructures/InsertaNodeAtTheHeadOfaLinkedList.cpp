//
//  InsertaNodeAtTheHeadOfaLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 23/10/2016.
//
//  https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node *next;
};

Node* Insert(Node *head,int data) {
    
    Node* newHead = new Node();
    newHead->data = data;
    newHead->next = head; //Head could be null, but who could care less :D.
    
    return newHead;
}
