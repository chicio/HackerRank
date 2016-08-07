//
//  LisasWorkbook.cpp
//  HackerRank
//
//  Created by Fabrizio Duroni on 07/08/16.
//
//  https://www.hackerrank.com/challenges/lisa-workbook

#include <iostream>

using namespace std;

int main() {
    
    /*
     There must be a better solution for sure (this one is a too much complex).
     I will find it, I promise :).
     */

    //n is the number of chapters.
    //k is the number of problem per pages.
    //t is the number of problems in the i-th chapter.
    int n, k, t;
    
    cin >> n >> k;
    
    //Problem to be counted: position == page on which they are printed.
    int specialProblems = 0;
    
    int startPage = 1;
    int pagePerChapter = 0;
    
    //Foreach chapter
    for(int i = 1; i <= n; i++) {
        
        cin >> t;
        
        pagePerChapter = t / k;
        
        if(t % k != 0) {
            
            //Last page if t doesn't fullfill it.
            pagePerChapter++;
        }
        
        int problemStartRange = 1;
        int problemEndRange = (pagePerChapter == 1 ? t : k);
        int currentCheckedPage = 1;
        int currentChapterPagesRange = startPage + pagePerChapter;
        
        //Foreach page.
        for(int currentPage = startPage; currentPage < currentChapterPagesRange; currentPage++) {
            
            //Scan problems range for current page.
            for(int currentProblem = problemStartRange; currentProblem <= problemEndRange; currentProblem++) {
                
                if(currentProblem == currentPage) {
                    
                    //Found a special problem.
                    specialProblems++;
                }
            }
            
            problemStartRange = problemEndRange + 1;
            problemEndRange = problemStartRange + (k - 1);

            if(currentCheckedPage == pagePerChapter - 1) {
                
                if(t % k != 0) {
                    
                    problemEndRange = problemStartRange + (t % k) - 1;
                }
            }
            
            currentCheckedPage++;
        }
        
        startPage += pagePerChapter;
    }
    
    cout << specialProblems;
    
    return 0;
}
