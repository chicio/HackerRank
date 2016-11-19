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

/*
 The exercise asks to implement a simple hashtable,
 but i decided to have fun and implement a generic hashtable
 using templates (that i could reuse on other challenges
 on hackerrank and in the "real programming life" if needed).
 
 NB.: use unordered_map if you love simple life :).
 */

/*!
 Node struct with generic data type.
 */
template <typename T>
struct Node {
    
    /// data contained in the node of generic type T.
    T data;
    /// Pointer to the next node.
    Node* next;
};

/*!
 Linked list generic class.
 */
template <typename T>
class LinkedList {
private:
    
    /// Head node of the linked list.
    Node<T>* head;

public:
    
    /*!
     Constructor.
     Initialize head to null pointer.
     */
    LinkedList() {
        
        head = nullptr;
    }
    
    /*!
     Insert a new node in the list.
     
     @param data the data to be inserted in a new node.
     */
    void insert(T data) {
        
        //Create the new node.
        Node<T>* newNode = new Node<T>();
        newNode->data = data;
        
        //Set new node as head if it does not exists yet.
        if (head == nullptr) {
            
            head = newNode;
            return;
        }
        
        //Insert node at the end of the linked list.
        Node<T>* currentNode = head;
        
        while (currentNode->next != nullptr) {
            
            currentNode = currentNode->next;
        }
        
        //Set new node as last.
        currentNode->next = newNode;
    }
    
    /*!
     Get a node with data.
     
     @param data the data to be searched.
     
     @returns the node with data received as input if exists, else false.
     */
    Node<T>* get(T data) {
        
        //Start from head.
        Node<T>* currentNode = head;
        
        //Search node and return it, or nullptr if not found.
        while (currentNode != nullptr) {
            
            if (currentNode->data == data) {
                
                return currentNode;
            }
            
            currentNode = currentNode->next;
        }
        
        return nullptr;
    }
    
    /*!
     Remove a node with data.
     
     @param data the data of the node to be removed.
     
     @returns true if removed, else false.
     */
    bool remove(T data) {
        
        if (head != nullptr && head->data == data) {
            
            Node<T>* nodeToBeDelete = head;
            head = head->next;
            delete nodeToBeDelete;
            
            return true;
        }
        
        //Start from head.
        Node<T>* currentNode = head;
        
        //Search node and return it, or nullptr if not found.
        while (currentNode != nullptr) {
            
            if (currentNode->next != nullptr && currentNode->next->data == data) {
                
                Node<T>* nodeToBeDelete = currentNode->next;
                currentNode->next = currentNode->next->next;
                delete nodeToBeDelete;
                
                return true;
            }
            
            currentNode = currentNode->next;
        }
        
        return false;
    }
    
    /*!
     Debug method.
     Print linked list.
     */
    void print() {
        
        Node<T>* currentNode = head;
        
        while (currentNode != nullptr) {
         
            cout << currentNode->data << " -> ";
            currentNode = currentNode->next;
        }
        
        cout << endl;
    }
};

/*!
 HashTable generic class.
 */
template <typename T>
class HashTable {
protected:
    
    /// Elements in the hash table (one key => possible multiple elements as a consequence of hash collision)
    vector<LinkedList<T>> elements;
    
public:
    
    /*!
     Constructor.
     Init the vector with length specified.
     
     @param length the length of the hash table.
     */
    HashTable(int length) {
        
        elements = vector<LinkedList<T>>(length);
    }
    
    /*!
     Insert a new element in th hash table.
     
     @param data data to be assigned to the new element of the hash table.
     */
    void insert(T data) {
        
        //Calculate hash and insert element in linked list at position.
        int hashPosition = hash(data);
        elements[hashPosition].insert(data);
    }
    
    /*!
     Get element from hash table (if it exists).
     
     @param data the data to be searched in the hashtable.
     
     @returns node found or nullptr.
     */
    Node<T>* get(T data) {
        
        //Calculate hash and get element with data in linked list at position.
        int hashPosition = hash(data);
        
        return elements[hashPosition].get(data);
    }
    
    /*!
     Remove element from hash table with data (if it exists).
     
     @param data the data to be removed from the hashtable.
     
     @returns true if node has been eliminated, else false.
     */
    bool remove(T data) {

        //Calculate hash and remove element.
        int hashPosition = hash(data);
        
        return elements[hashPosition].remove(data);
    }
    
    /*!
     Debug method.
     Print all hash table.
     */
    void print() {
        
        for (int i = 0; i < elements.size(); i++) {
            
            elements[i].print();
        }
    }
    
    /*!
     Hash method.
     This is a pure virtual method that every
     subclass must implements with its specific
     hash function.
     
     @param data data on which hash table calculate hash.
     
     @returns position in the hash table.
     */
    virtual int hash(T data) = 0;
};

/*!
 Hash table with string data type implemenation.
 */
class StringHashTable : public HashTable<string> {
public:
    
    /*!
     Constructor.
     
     @param length the length of the hash table.
     */
    StringHashTable(int length) : HashTable<string>(length) {}
    
    /*!
     Hash function specific for string data type.
     
     @param data string data on which hash function is applied.
     
     @returns position in the hash table.
     */
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
    
    //Create hash table with magazine words.
    StringHashTable hashTable((int)magazine.size());
    
    for (int i = 0; i < magazine.size(); i++) {
        
        hashTable.insert(magazine[i]);
    }
    
    //Search ransom words in hash table:
    //if one doesn't exists then message could
    //not be completed.
    for (int i = 0; i < ransom.size(); i++) {
        
        if (hashTable.get(ransom[i]) == nullptr) {
            
            return false;
        } else {
            
            //Element used in ransom message, so we remove it from hash table.
            //In this way it is possible to keep track if the
            //occurrencies of a word are the same in the magazine
            //and in the ransom.
            hashTable.remove(ransom[i]);
        }
    }
    
    return true;
}

int main() {
    
    int m;
    int n;
    
    cin >> m >> n;
    
    vector<string> magazine(m);
    
    for (int magazine_i = 0; magazine_i < m; magazine_i++) {
        
        cin >> magazine[magazine_i];
    }
    
    vector<string> ransom(n);
    
    for (int ransom_i = 0;ransom_i < n;ransom_i++) {
        
        cin >> ransom[ransom_i];
    }
    
    if (ransom_note(magazine, ransom)) {
        
        cout << "Yes" << endl;
    } else {
        
        cout << "No" << endl;
    }
    
    return 0;
}
