//
//  Day13AbstractClasses.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 30/09/2016.
//
//  https://www.hackerrank.com/challenges/30-abstract-classes

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Book{
protected:
    
    string title;
    string author;
    
public:

    Book(string t,string a){
        
        title = t;
        author = a;
    }
    
    virtual void display() = 0;
};

class MyBook : public Book {
protected:
    
    int price;
    
public:
    
    MyBook(string title, string author, int aPrice) : Book(title, author), price{aPrice} {};
    
    void display() {
        
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
 
    string title,author;
    int price;
    
    getline(cin,title);
    getline(cin,author);
    
    cin >> price;
    
    MyBook novel(title,author,price);
    novel.display();
    
    return 0;
}
