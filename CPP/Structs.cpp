//
//  Structs.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/c-tutorial-struct

#include <iostream>

using namespace std;

struct Student {
    
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}
