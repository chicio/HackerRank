//
//  RecursionDavisStaircase.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 05/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-recursive-staircase

#import <Foundation/Foundation.h>

/*!
 This problem is ana example of the use 
 of memoization: cache previous result values
 in a recursive problem to be reused later
 (avoid duplicated calculation).
 */
int staircasesCombination(int length) {

    static NSMutableArray *memoizator;

    if (length == 0) {
        
        return 1;
    }
    
    if (length < 0) {
     
        return 0;
    }

    if (memoizator == nil) {
        
        memoizator = [[NSMutableArray alloc] initWithCapacity:length];
        
        for (int i = 0; i < length; i++) {
            
            [memoizator addObject:[NSNumber numberWithInt:-1]];
        }
    }
    
    if (memoizator.count > length && [memoizator[length] intValue] > -1) {
     
        return [memoizator[length] intValue];
    }
    
    int staircaseLength = staircasesCombination(length - 1) +
                          staircasesCombination(length - 2) +
                          staircasesCombination(length - 3);
    
    memoizator[length] = [NSNumber numberWithInt:staircaseLength];
    
    return staircaseLength;
}

int main(int argc, const char * argv[]) {
    
    @autoreleasepool {
        
        int s;
        scanf("%i",&s);
        
        for (int a0 = 0; a0 < s; a0++) {
            
            int n;
            scanf("%i",&n);
            
            printf("%d\n", staircasesCombination(n));
        }
    }
    
    return 0;
}
