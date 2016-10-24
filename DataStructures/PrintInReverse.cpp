//
//  PrintInReverse.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 24/10/2016.
//
//  https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse

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

void ReversePrint(Node *head) {

    //No linked list: exit immediately.
    if (head == nullptr) {
        
        return;
    }
    
    //It is possible to reverse the linked list (recursion print),
    //but here we just need to print out the values :).
    //Create linked list message in reverse order.
    string reverseLinkedList("");
    Node* currentNode = head;
    
    while (currentNode != nullptr) {
        
        reverseLinkedList = to_string(currentNode->data) + "\n" + reverseLinkedList;
        currentNode = currentNode->next;
    }
    
    cout << reverseLinkedList;
}
