//
//  AbstractClassesPolymorphism.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 20/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/abstract-classes-polymorphism

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

struct Node {
    
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {
protected:
    
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
};

class LRUCache : Cache {
public:
    
    LRUCache(int aCapacity) {
        
        cp = aCapacity;
        head = nullptr;
        tail = nullptr;
    }
    
    void set(int index, int value) {
        
        if(mp.count(index) == 1) {
            
            //Key exists.
            mp[index]->value = value;
            setHead(detachNode(index));
        } else {
            
            //Key doesn't exists.
            //It became the new head of the list.
            Node* newNode = new Node(index, value);
            setHead(newNode);
            
            if(mp.size() > cp) {
                
                Node* nodeToBeDeleted = detachNode(tail->key);
                delete nodeToBeDeleted;
            }
        }
    }
    
    int get(int index) {
       
        if(mp.count(index) > 0) {
            
            setHead(detachNode(index));
            
            return mp[index]->value;
        }
        
        return -1;
    }

private :
    
    void setHead(Node* node) {
        
        if(head) {
            
            Node* oldHead = head;
            oldHead->prev = node;
            node->next = head;
            node->prev = NULL;
        }
        
        head = node;
        
        if(!tail) {
            
            //First time set head.
            tail = head;
        }
        
        mp[node->key] = node;
    }
    
    Node* detachNode(int index) {
        
        Node* nodeDetached = mp[index];
        mp.erase(index);
        
        //Update prev or head.
        if(nodeDetached->prev != NULL) {
            
            nodeDetached->prev->next = nodeDetached->next;
        } else {
            
            head = nodeDetached->next;
        }
        
        //Update next or tail.
        if(nodeDetached->next != NULL) {
            
            nodeDetached->next->prev = nodeDetached->prev;
        } else {
            
            tail = nodeDetached->prev;
        }
        
        return nodeDetached;
    }
    
};

int main() {
    
    int n, capacity, i;
    
    cin >> n >> capacity;
    
    LRUCache l(capacity);
    
    for(i=0; i<n; i++) {
        
        string command;
        
        cin >> command;
        
        if(command == "get") {
            
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } else if(command == "set") {
            
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    
    return 0;
}
