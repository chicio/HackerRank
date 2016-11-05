//
//  TimeComplexityPrimality.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 04/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-big-o

#import <Foundation/Foundation.h>

/*!
 Testing primality using trial division method.
 
 @see https://en.wikipedia.org/wiki/Trial_division
 
 @param number the number to be tested.
 
 @returns true if number is a prime, else false.
 */
BOOL isPrime(int number) {
    
    if (number <= 1) {
        
        return false;
    }
    
    if (number == 2) {
        
        return true;
    }
    
    for (int i = 2; i <= sqrt(number); i++) {
        
        if (number % i == 0) {
            
            return NO;
        }
    }
    
    return YES;
}

int main(int argc, const char * argv[]){
    
    @autoreleasepool {
        
        int p;
        scanf("%i",&p);
        
        for (int a0 = 0; a0 < p; a0++) {
            
            int n;
            scanf("%i",&n);
            
            if (isPrime(n)) {
             
                printf("Prime\n");
            } else {
                
                printf("Not prime\n");
            }
        }
    }
    
    return 0;
}
