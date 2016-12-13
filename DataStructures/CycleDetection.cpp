//
//  CycleDetection.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/12/2016.
//  
//  https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node* next;
};

bool has_cycle(Node* head) {

    //Use Floyd's cycle detection algorithm.
    Node* slow = head;
    Node* fast = head;
    
    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
        
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            
            return true;
        }
    }
    
    return false;
}
