//
//  DynamicArray.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 27/09/2016.
//
//  https://www.hackerrank.com/challenges/dynamic-array

#include <vector>
#include <iostream>

using namespace std;

int main() {

    //n is the number of sequence and of element in each sequence.
    //q is the number of query.
    int n;
    int q;
    
    cin >> n >> q;
    
    vector<vector<int>> seqList(n);

    //queryType is the type of the query.
    //x is the first element of the query.
    //y is the second element of the query.
    int queryType;
    int x;
    int y;
    
    //Store last result.
    int lastAns = 0;
    
    for (int i = 0; i < q; i++) {
        
        cin >> queryType >> x >> y;

        //Common query part: find sequence.
        int seqListPosition = (x ^ lastAns) % n;
        
        if (queryType == 1) {
            
            //Add elements.
            seqList[seqListPosition].push_back(y);
        }
        
        if (queryType == 2) {

            //Get last results.
            lastAns = seqList[seqListPosition][y % seqList[seqListPosition].size()];
            cout << lastAns << endl;
        }
    }
    
    return 0;
}
