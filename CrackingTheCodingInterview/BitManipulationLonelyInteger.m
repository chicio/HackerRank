//
//  BitManipulationLonelyInteger.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 04/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-lonely-integer

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]){
    
    @autoreleasepool {
        
        int n;
        scanf("%i",&n);
        int value = 0;
        int currentValue;
        
        for(int a_i = 0; a_i < n; a_i++) {
            
            scanf("%d",&currentValue);
            value ^= currentValue;
        }
        
        printf("%d", value);
        
    }
    
    return 0;
}
