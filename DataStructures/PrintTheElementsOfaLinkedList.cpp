//
//  PrintTheElementsOfaLinkedList.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/10/2016.
//
//  https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list

#include <iostream>

using namespace std;

struct Node {
    
    int data;
    struct Node *next;
};
 
void Print(Node *head) {

    Node *currentNode = head;
    
    while (currentNode) {
        
        //Print current element.
        cout << currentNode->data << endl;
        
        //Update current node.
        currentNode = currentNode->next;
    }
}
