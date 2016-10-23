//
//  DeleteaNode.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 23/10/2016.
//
//  https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list

/*!
 C alike struct definition.
 The attribute Node is be declared with struct
 because in C, Node is not yet defined at this point.
 */
struct Node {
    
    int data;
    struct Node* next;
};

Node* Delete(Node* head, int position) {
    
    //Position 0: remove head.
    if (position == 0) {
        
        Node* oldHead = head;
        head = head->next;
        
        delete oldHead;
        
        return head;
    }

    //Search node to be deleted.
    int currentPosition = 1;
    Node* nodeBeforeDeletePosition = head;
    
    while (currentPosition != position) {
        
        nodeBeforeDeletePosition = nodeBeforeDeletePosition->next;
        currentPosition++;
    }
    
    //Delete node.
    Node *nodeToBeDeleted = nodeBeforeDeletePosition->next;
    nodeBeforeDeletePosition->next = nodeBeforeDeletePosition->next->next;
    
    delete nodeToBeDeleted;
    
    return head;
}
