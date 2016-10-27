//
//  StringsMakingAnagrams.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 26/10/2016.
//
//  https://www.hackerrank.com/challenges/ctci-making-anagrams

#include <string>
#include <iostream>
#include <vector>

const char firstLetterOfAlphabetASCII = 'a';

using namespace std;

/*!
 Calculate the number of delete needed to 
 transform to strings anagrams.
 
 @param a first string that we want to transform in anagrams.
 @param b second string that we want to transform in anagrams.
 
 @returns number of deletion needed to transform the two string in an anagrams.
 */
int numberNeeded(string a, string b) {

    //These vectors will contain the number of times a letter appear in string.
    vector<int> lettersCountA(26);
    vector<int> lettersCountB(26);
    
    for (int i = 0; i < a.length(); i++) {
        
        //Use current string char as position in the lettersCountA vectors.
        //NB.: subtract 'a' to use current char as 0 based index in letterCountA vectors
        lettersCountA[a[i] - firstLetterOfAlphabetASCII]++;
    }
    
    for (int i  = 0; i < b.length(); i++) {

        //Use current string char as position in the lettersCountB vectors.
        //NB.: subtract 'a' to use current char as 0 based index in letterCountB vectors
        lettersCountB[b[i] - firstLetterOfAlphabetASCII]++;
    }
    
    int numberOfDelete = 0;
    
    for (int i = 0; i < 26; i++) {
        
        //The absolute value of the difference between the count of appearence of
        //a letter inside the two string gives us the number of delete to be applied to
        //the two strings to obtain an anagram. Sum them to obtain the
        //total number of delete.
        numberOfDelete += abs(lettersCountA[i] - lettersCountB[i]);
    }
    
    return numberOfDelete;
}

int main() {
    
    string a;
    string b;
    
    cin >> a;
    cin >> b;
    
    cout << numberNeeded(a, b) << endl;
    
    return 0;
}
