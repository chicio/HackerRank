//
//  BoxIt.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/box-it

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box {
    
    long long l;
    long long b;
    long long h;
    
public:
    
    long long getLength() {
        
        return l;
    }
    
    long long getBreadth() {
        
        return b;
    }
    
    long long getHeight() {
        
        return h;
    }
    
    Box() {
        l = 0;
        b = 0;
        h = 0;
        
        BoxesCreated++;
    }
    
    Box(int newL,int newB, int newH) {
        
        l = newL;
        b = newB;
        h = newH;
        
        BoxesCreated++;
    }
    
    Box(Box& otherBox) {
        
        l = otherBox.getLength();
        b = otherBox.getBreadth();
        h = otherBox.getHeight();
        
        BoxesCreated++;
    }
    
    long long CalculateVolume() {
        
        long long volume = l * b * h;
        
        return volume;
    }
    
    bool operator<(Box& otherBox) {
        
        if(l < otherBox.getLength()) {
            
            return true;
        }
        
        if(b < otherBox.getBreadth() && l == otherBox.getLength()) {
            
            return true;
        }
        
        if(h < otherBox.getHeight() && b == otherBox.getBreadth() && l == otherBox.getLength()) {
            
            return true;
        }
        
        return false;
    }
    
    ~Box() {
        
        BoxesDestroyed++;
    }
};

ostream& operator<<(ostream& os, Box box) {
    
    os << box.getLength() << ' ' << box.getBreadth() << ' ' << box.getHeight();
    
    return os;
}

void check2() {
    
    int n;
    
    cin>>n;
    
    Box temp;
    
    for(int i=0;i<n;i++) {
        
        int type;
        
        cin >> type;
        
        if(type ==1) {
            
            cout<<temp<<endl;
        }
        
        if(type == 2) {
            
            int l,b,h;
            
            cin >> l>> b >> h;
            
            Box NewBox(l,b,h);
            
            temp=NewBox;
            
            cout<<temp<<endl;
        }
        
        if(type == 3) {
            
            int l,b,h;
            
            cin >> l >> b >> h;
            
            Box NewBox(l,b,h);
            
            if(NewBox<temp) {
                
                cout<<"Lesser"<<endl;
            } else {
                
                cout<<"Greater"<<endl;
            }
        }
        
        if(type==4) {
            
            cout<<temp.CalculateVolume()<<endl;
        }
        
        if(type==5) {
            
            Box NewBox(temp);
            
            cout << NewBox << endl;
        }
    }
}

int main() {
    
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    
    check2();
    
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
