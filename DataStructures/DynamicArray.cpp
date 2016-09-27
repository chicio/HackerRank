//
//  DynamicArray.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 27/09/2016.
//
//  https://www.hackerrank.com/challenges/dynamic-array

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    //n is the number of sequence and of element in each sequence.
    //q is the number of query.
    int n;
    int q;
    
    cin >> n >> q;
    
    vector<vector<int>> seqList(n);

//    for (int i = 0; i < n; i++) {
//        
//        //Create n list of n elements.
//        seqList[i] = vector<int>();
//    }
    
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

        int seqListPosition = (x ^ lastAns) % n;
        
        if (queryType == 1) {
            
            seqList[seqListPosition].push_back(y);
        }
        
        if (queryType == 2) {
            
            lastAns = seqList[seqListPosition][y] % seqList[seqListPosition].size();
            cout << lastAns << endl;
        }
        
        cout << seqList[seqListPosition].size() << endl;
    }
    
    return 0;
}
