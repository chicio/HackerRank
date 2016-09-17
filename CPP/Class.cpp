//
//  Class.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//
//  https://www.hackerrank.com/challenges/c-tutorial-class

#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    
    int age;
    string first_name;
    string last_name;
    int standard;
    
public:
    
    void set_age(int new_age) {
        
        age = new_age;
    }
    
    int get_age() {
        
        return age;
    }
    
    void set_first_name(string new_first_name) {
        
        first_name = new_first_name;
    }
    
    string get_first_name() {
        
        return first_name;
    }
    
    void set_last_name(string new_last_name) {
        
        last_name = new_last_name;
    }
    
    string get_last_name() {
        
        return last_name;
    }
    
    void set_standard(int new_standard) {
        
        standard = new_standard;
    }
    
    int get_standard() {
        
        return standard;
    }
    
    string to_string() {
        
        return std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);
    }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
