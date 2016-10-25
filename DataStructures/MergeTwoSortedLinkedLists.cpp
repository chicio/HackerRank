//
//  MergeTwoSortedLinkedLists.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 25/10/2016.
//
//  https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists

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

Node* MergeLists(Node *headA, Node* headB) {

    Node* result;
    
    if (headA == nullptr) {
        
        return headB;
    }
    
    if (headB == nullptr) {
        
        return headA;
    }
    
    if (headA->data <= headB->data) {
        
        result = headA;
        result->next = MergeLists(headA->next, headB);
    } else {
        
        result = headB;
        result->next = MergeLists(headA, headB->next);
    }
    
    return result;
}
