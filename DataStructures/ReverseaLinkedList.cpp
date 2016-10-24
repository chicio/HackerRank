//
//  ReverseaLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 24/10/2016.
//
//  https://www.hackerrank.com/challenges/reverse-a-linked-list

#include <iostream>
#include <string>

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

Node* Reverse(Node* head) {
    
    Node* currentNode = head;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
    
    while (currentNode != nullptr) {

        //Get ref to next node.
        nextNode = currentNode->next;
        //Update next to previous node.
        currentNode->next = prevNode;
        //Previous node is now current node.
        prevNode = currentNode;
        //Current node is next node.
        currentNode = nextNode;
    }
    
    //Update head with last previous node.
    head = prevNode;

    return head;
}
