//
//  BiggerIsGreater.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 02/08/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/bigger-is-greater

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    
    //Generate permutation in lexicographic order in place:
    //https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
    
    //n is the number of word to analyze.
    int n;
    //Current analyzed word.
    string currentWord;
    //Copy of the original string.
    string originalCurrentWord;
    
    cin >> n;
    
    for (int currentWordPosition = 0; currentWordPosition < n; currentWordPosition++) {
        
        cin >> currentWord;
        
        //Copy original string.
        originalCurrentWord = currentWord;
        
        //Count number of permutation for current word.
        int numberOfPermutation = 0;
        //Flag used to check the status.
        bool stopPermutation = false;
        //Flag used to check the status of the current permutation.
        bool foundK, foundI;
        
        while (!stopPermutation) {
            
            foundK = false;
            foundI = false;
            
            for (int i = (int)currentWord.length() - 2; i >= 0; i--) {
                
                //Search largest i such that currentWord[i] < currentWord[i + 1]
                if(currentWord.at(i) < currentWord.at(i + 1) && !foundK) {
                    
                    foundK = true;
                    
                    for (int h = (int)currentWord.length() - 1; h > i; h--) {
                        
                        //Search largest h such that currentWord[i] < currentWord[h]
                        if(currentWord.at(i) < currentWord.at(h) && !foundI) {
                            
                            foundI = true;
                            
                            //Swap char at position i with char ar position h.
                            swap(currentWord[i], currentWord[h]);
                            //Reverse currentWord in range [i + 1, n], with n = size of currentWord.
                            reverse(currentWord.begin() + i + 1, currentWord.end());
                            //Increase permutation counter.
                            numberOfPermutation++;
                        }
                    }
                }
            }
            
            //If no k found permutation are over.
            if(!foundK) {
                
                stopPermutation = true;
            }
            
            //First lexicographical greater string found.
            if(currentWord > originalCurrentWord) {
                
                stopPermutation = true;
            }
        }
        
        if(numberOfPermutation == 0) {
            
            //No permutation completed, so no answer.
            cout << "no answer" << endl;
        } else {
            
            //Print calculated string
            cout << currentWord << endl;
        }
    }
    
    return 0;
}
