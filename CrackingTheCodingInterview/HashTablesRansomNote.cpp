//
//  HashTablesRansomNote.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 27/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-ransom-note

#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
public:
    
    Node<T>* head;
    
    LinkedList() {
        
        head = nullptr;
    }
    
    void insert(T data) {
        
        Node<T>* newNode = new Node<T>();
        newNode->data = data;
     
        if (head == nullptr) {
            
            head = newNode;
            return;
        }
        
        Node<T>* currentNode = head;
        
        while (currentNode->next != nullptr) {
            
            currentNode = currentNode->next;
        }
        
        currentNode->next = newNode;
    }
};

template <typename T>
class HashTable {
public:
    
    vector<LinkedList<T>> elements;
    
    HashTable(int length) {

        elements = vector<LinkedList<T>>(length);
    }
    
    void insert(T data) {
        
        int hashPosition = hash(data);
        elements[hashPosition].insert(data);
    }
    
    virtual int hash(T data) = 0;
};

class StringHashTable : public HashTable<string> {
public:
    
    StringHashTable(int length) : HashTable<string>(length) {}
    
    int hash(string data) {
        
        int sumOfCharsOfString = 0;
        
        for (int i = 0; i < data.length(); i++) {
            
            sumOfCharsOfString += data[i];
        }
        
        int index = sumOfCharsOfString % elements.size();
        
        return index;
    }
};

bool ransom_note(vector<string> magazine, vector<string> ransom) {
 
    StringHashTable hashTable((int)magazine.size());
    
    for (int i = 0; i < magazine.size(); i++) {
        
        hashTable.insert(magazine[i]);
    }
    
    return true;
}

int main(){
    
    int m;
    int n;
    
    cin >> m >> n;
    
    vector<string> magazine(m);
    
    for (int magazine_i = 0; magazine_i < m; magazine_i++) {
        
        cin >> magazine[magazine_i];
    }
    
    vector<string> ransom(n);
    
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
        
        cin >> ransom[ransom_i];
    }
    
    if(ransom_note(magazine, ransom)) {
        
        cout << "Yes\n";
    }
    else {
        
        cout << "No\n";
    }
        
    return 0;
}
