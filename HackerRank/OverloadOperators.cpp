//
//  main.cpp
//  GraphTest
//
//  Created by Duroni Fabrizio on 04/08/16.
//  Copyright © 2016 Duroni Fabrizio. All rights reserved.
//
//  https://www.hackerrank.com/challenges/overload-operators

//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    
    int a,b;
    
    void input(string s) {
        
        int v1=0;
        int i=0;
        
        while(s[i]!='+') {
            
            v1=v1*10+s[i]-'0';
            i++;
        }
        
        while(s[i]==' ' || s[i]=='+'||s[i]=='i') {
            
            i++;
        }
        
        int v2=0;
        while(i < s.length()) {
            
            v2=v2*10+s[i]-'0';
            i++;
        }
        
        a = v1;
        b = v2;
    }
};

Complex operator+(const Complex& complex1, const Complex& complex2) {
    
    Complex result;
    result.a = complex1.a + complex2.a;
    result.b = complex1.b + complex2.b;
    
    return result;
}

ostream& operator<<(ostream& os, const Complex& complex) {
    
    os << complex.a << "+i" << complex.b;
    return os;
}

int main() {
    
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    cout << z <<endl;
}
