//
//  RectangleArea.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 25/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/rectangle-area

#include <iostream>

using namespace std;

class Rectangle {
protected:
    
    int width;
    int height;
    
public:
    
    void display() {
        
        cout << width << ' ' << height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    
    void read_input() {
        
        cin >> width >> height;
    }
    
    void display() {
        
        cout << width * height << endl;
    }
};

int main() {
    
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}