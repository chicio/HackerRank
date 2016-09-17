//
//  AttendingWorkshops.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/08/16.
//
//  https://www.hackerrank.com/challenges/attending-workshops

#include <iostream>

using namespace std;

struct Workshop {

    int start_time;
    int end_time;
    int duration;
};

struct Available_Workshops {
    
    int n;
    Workshop* workshops;
};

Available_Workshops* initialize (int start_time[], int duration[], int n) {
    
    Available_Workshops* available_workshops = new Available_Workshops();
    available_workshops->n = n;
    available_workshops->workshops = new Workshop[n];
    
    for(int i = 0; i < n; i++) {
        
        Workshop currentWorkshop;
        currentWorkshop.start_time = start_time[i];
        currentWorkshop.duration = duration[i];
        currentWorkshop.end_time = currentWorkshop.start_time + currentWorkshop.duration;
        
        available_workshops->workshops[i] = currentWorkshop;
    }
    
    return available_workshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    
    sort(ptr->workshops, ptr->workshops + ptr->n, [](Workshop &first,Workshop &second) {
        
        return first.end_time < second.end_time;
    });

    int current_end_time = 0;
    int numberOfCoursesThatDoesntOverlap = 0;
    
    for (auto i = ptr->workshops; i < (ptr->workshops) + ptr->n; i++) {
        
        if(i->start_time >= current_end_time) {
            
            numberOfCoursesThatDoesntOverlap++;
            current_end_time = i->end_time;
        }
    }
    
    return numberOfCoursesThatDoesntOverlap;
}

int main(int argc, char *argv[]) {
    
    int n; // number of workshops
    cin >> n;
    
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];
    
    for(int i=0; i < n; i++){
        
        cin >> start_time[i];
    }
    
    for(int i = 0; i < n; i++){
        
        cin >> duration[i];
    }
    
    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    
    return 0;
}
