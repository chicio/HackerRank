//
//  CompareTwoLinkedLists.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 25/10/2016.
//
//  https://www.hackerrank.com/challenges/compare-two-linked-lists

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

int CompareLists(Node* headA, Node* headB) {

    Node* currentNodeA = headA;
    Node* currentNodeB = headB;
    
    //Loop on lists.
    while (currentNodeA != nullptr || currentNodeB != nullptr) {
        
        //If one of the head node is null or
        //data of the nodes doesn't match.
        if ((currentNodeA != nullptr && currentNodeB == nullptr) ||
            (currentNodeB != nullptr && currentNodeA == nullptr) ||
            (currentNodeA->data != currentNodeB->data)) {
            
            return 0;
        }
        
        currentNodeA = currentNodeA->next;
        currentNodeB = currentNodeB->next;
    }
    
    return 1;
}
