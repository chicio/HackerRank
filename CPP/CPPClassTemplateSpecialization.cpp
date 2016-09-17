//
//  CPPClassTemplateSpecialization.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 20/08/16.
//
//  https://www.hackerrank.com/challenges/cpp-class-template-specialization

#include <iostream>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template<>
struct Traits<Fruit> {

    static string name(int fruitIndex) {
        
        string fruitName;
        
        switch (fruitIndex) {
            case 0:
                fruitName = "apple";
                break;
            case 1:
                fruitName = "orange";
                break;
            case 2:
                fruitName = "pear";
                break;
            default:
                fruitName = "unknown";
                break;
        }
        
        return fruitName;
    }
};

template<>
struct Traits<Color> {
    
    static string name(int colorIndex) {
        
        string colorName;
        
        switch (colorIndex) {
            case 0:
                colorName = "red";
                break;
            case 1:
                colorName = "green";
                break;
            case 2:
                colorName = "orange";
                break;
            default:
                colorName = "unknown";
                break;
        }
        
        return colorName;
    }
};

int main() {
    
    int t = 0;
    
    std::cin >> t;
    
    for (int i=0; i!=t; ++i) {
        
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
