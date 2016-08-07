//
//  VirtualFunctions.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 06/08/16.
//
//  https://www.hackerrank.com/challenges/virtual-functions

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int sequentiaProfessorId = 1;
static int sequentialStudentId = 1;

class Person {
protected:
    
    /// Name of the person.
    string name;
    /// Age of the persone.
    int age;
    
public:
    
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person {
private:

    /// Id of the person.
    const int curId;
    /// Publications of the professor.
    int publications;
    
public:

    /*!
     Default constructor.
     Assign sequential id using static property.
     */
    Professor() : curId{sequentiaProfessorId++} {}

    void getdata() {
        
        cin >> name >> age >> publications;
    }
    
    void putdata() {
        
        cout << name << " " << age << " " <<  publications << " " << curId << endl;
    }
};

class Student : public Person {
private:
    
    /// Id of the person.
    const int curId;
    /// Marks of the students.
    int marks[6];
    /// Marks sum;
    int marksSum;
    
public:
    
    /*!
     Default constructor.
     Assign sequential id using static property.
     */
    Student() : curId{sequentialStudentId++} {}
    
    void getdata() {
        
        cin >> name >> age;
        
        marksSum = 0;
        
        for (int i = 0; i < 6; i++) {
            
            cin >> marks[i];
            marksSum += marks[i];
        }
    }
    
    void putdata() {
        
        cout << name << " " << age << " " << marksSum << " " << curId << endl;
    }
};

int main(){
    
    int n, val;
    
    cin >> n; //The number of objects that is going to be created.
    
    Person* per[n];
    
    for(int i = 0; i < n; i++){
        
        cin >> val;
        
        if(val == 1){
            
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        } else {

            per[i] = new Student; // Else the current object is of type Student
        }
        
        per[i]->getdata(); // Get the data from the user.
    }
    
    for(int i=0; i < n; i++) {

        per[i]->putdata(); // Print the required output for each object.
    }
    
    return 0;
}
