//
//  SortingComparator.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 27/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-comparator-sorting

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    
    string name;
    int score;
};

/*!
 Comparator used to sort the vector of players.
 Comparison function object that match Compare criteria.
 
 @see http://en.cppreference.com/w/cpp/algorithm/sort
 */
struct PlayerComparator {
    
    /*!
     Comparison operator (see link above comp(a, b)).
     
     @param p1 first player in the comparison.
     @param p2 second player in the comparison.
     
     @returns bool based on defined conditions.
     */
    inline bool operator() (const Player& p1, const Player& p2) {

        //Test players by names and scores.
        if (p1.score == p2.score) {
            
            return p1.name < p2.name;
        }
        
        return p1.score > p2.score;
    }
};

int main() {
    
    int n;
    
    cin >> n;
    
    vector<Player> players;
    string name;
    int score;
    
    for (int i = 0; i < n; i++) {
        
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    sort(players.begin(), players.end(), PlayerComparator());
    
    for (int i = 0; i < players.size(); i++) {
        
        cout << players[i].name << " " << players[i].score << endl;
    }
    
    return 0;
}
