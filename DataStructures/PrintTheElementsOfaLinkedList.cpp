//
//  PrintTheElementsOfaLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/10/2016.
//
//  https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list

#include <iostream>

using namespace std;

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node *next;
};
 
void Print(Node *head) {

    Node *currentNode = head;
    
    while (currentNode != nullptr) {
        
        //Print current element.
        cout << currentNode->data << endl;
        
        //Update current node.
        currentNode = currentNode->next;
    }
}
