//
//  GameOfTwoStacks.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 23.03.17.
//  Copyright © 2017 Fabrizio Duroni. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int numberOfGames;
    
    cin >> numberOfGames;
    
    for (int a0 = 0; a0 < numberOfGames; a0++) {
        
        int stackASize;
        int stackBSize;
        int maxStackElementsStack;
        
        cin >> stackASize >> stackBSize >> maxStackElementsStack;
        
        vector<int> stackA(stackASize);
        vector<int> stackB(stackBSize);
        
        for(int a_i = stackASize - 1; a_i >= 0; a_i--) {
            
            cin >> stackA[a_i];
        }
        
        for(int b_i = stackBSize - 1; b_i >= 0; b_i--) {
            
            cin >> stackB[b_i];
        }
        
        int currentStackElementsSum = 0;
        int numberOfElementRemoved = 0;
        
        while (currentStackElementsSum <= maxStackElementsStack) {
            
            int stackAElement = stackA.size() > 0 ? stackA.back() : INT_MAX;
            int stackBElement = stackB.size() > 0 ? stackB.back() : INT_MAX;
            
            if (stackAElement > stackBElement) {
                
                currentStackElementsSum += stackBElement;
                stackB.pop_back();
            } else {

                currentStackElementsSum += stackAElement;
                stackA.pop_back();
            }
            
            numberOfElementRemoved++;
        }
        
        cout << numberOfElementRemoved - 1 << endl;
    }
    
    cout << "test";
    
    return 0;
}
