//
//  LinkedListsDetectaCycle.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 01/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-linked-list-cycle

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

/*!
 Detect a cycle in a linked list.
 Detection is done using Floyd’s cycle algorithm.
 
 @param head the head of the linked list.
 */
bool has_cycle(Node* head) {

    Node* slowNode = head;
    Node* fastNode = head;
    
    while (slowNode != nullptr && fastNode != nullptr && fastNode->next != nullptr) {
        
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
        
        if (slowNode == fastNode) {
            
            return true;
        }
    }
    
    return false;
}
