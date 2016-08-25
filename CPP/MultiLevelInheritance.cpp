//
//  MultiLevelInheritance.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 25/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/multi-level-inheritance-cpp

#include <iostream>

using namespace std;

class Triangle {
public:
    
    void triangle() {
        
        cout << "I am a triangle" << endl;
    }
};

class Isosceles : public Triangle {
public:
    
    void isosceles(){
        
        cout << "I am an isosceles triangle" << endl;
    }
};

class Equilateral: public Isosceles {
public:
    
    void equilateral() {
        
        cout << "I am an equilateral triangle" << endl;
    }
};

//Write your code here.
int main(){
    
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
