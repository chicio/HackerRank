//
//  BinarySearchIceCreamParlor.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 04/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-ice-cream-parlor

#import <Foundation/Foundation.h>

//******** Binary Search definition ********//
//Implemented as exercise.

//Public interface
@interface BinarySearch : NSObject

+ (bool)binarySearch:(NSArray *)array element:(id)elementToBeFound;
+ (bool)binarySearchRecursive:(NSArray *)array element:(id)elementToBeFound left:(int)leftIndex right:(int)rightIndex;

@end

//Implementation
@implementation BinarySearch

+ (bool)binarySearch:(NSArray *)array element:(id)elementToBeFound {
    
    int leftIndex = 0;
    int rightIndex = (int)array.count - 1;
    
    while (leftIndex <= rightIndex) {
        
        int mid = (leftIndex + rightIndex) / 2;
        
        if ([array[mid] isEqual:elementToBeFound]) {
            
            return true;
        } else if ([elementToBeFound isLessThan:array[mid]]) {
            
            rightIndex = mid - 1;
        } else {
            
            leftIndex = mid + 1;
        }
    }
    
    return false;
}

+ (bool)binarySearchRecursive:(NSArray *)array element:(id)elementToBeFound left:(int)leftIndex right:(int)rightIndex {
    
    if (leftIndex > rightIndex) {
        
        return false;
    }
    
    int mid = (leftIndex + rightIndex) / 2;
    
    if ([array[mid] isEqual:elementToBeFound]) {
        
        return true;
    } else if ([elementToBeFound isLessThan:array[mid]]) {
        
        return [self binarySearchRecursive:array element:elementToBeFound left:leftIndex right:mid - 1];
    } else {
        
        return [self binarySearchRecursive:array element:elementToBeFound left:mid + 1 right:rightIndex];
    }
}

@end


//******** Ice Cream definition ********//

@interface IceCream : NSObject

@property (nonatomic, assign) int identifier;
@property (nonatomic, assign) int price;

@end

@implementation IceCream

- (NSComparisonResult)compare:(IceCream *)otherIceCream {
    
    if (self.price < otherIceCream.price) {
        
        return NSOrderedAscending;
    } else if (self.price > otherIceCream.price) {
        
        return NSOrderedDescending;
    } else {
        
        return NSOrderedSame;
    }
}

/*!
 Honestly, I searched for inspiration.....
 
 @see http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
 */
+ (void)modifiedSearch:(NSArray *)array sum:(int)sumToBeFound {
    
    int leftIndex = 0;
    int rightIndex = (int)array.count - 1;
    
    IceCream *icOne;
    IceCream *icTwo;
    
    int currentSum = 0;
    
    while (leftIndex < rightIndex) {
        
        icOne = array[leftIndex];
        icTwo = array[rightIndex];
        currentSum = icOne.price + icTwo.price;
        
        if (currentSum == sumToBeFound) {
            
            if (icOne.identifier > icTwo.identifier) {
                
                printf("%d %d\n", icTwo.identifier, icOne.identifier);
            } else {
                
                printf("%d %d\n", icOne.identifier, icTwo.identifier);
            }
            
            break;
        } else if (currentSum > sumToBeFound) {
            
            rightIndex--;
        } else {
            
            leftIndex++;
        }
    }
}

@end


//******** Main ********//

int main(int argc, const char * argv[]) {
    
    @autoreleasepool {
        
        int t;
        scanf("%i",&t);
        
        for(int a0 = 0; a0 < t; a0++) {
            
            int m;
            int n;
            
            scanf("%i",&m);
            scanf("%i",&n);
            
            int currentNumber;
            NSMutableArray *a = [NSMutableArray arrayWithCapacity:n];
            
            for (int a_i = 0; a_i < n; a_i++) {
                
                scanf("%d", &currentNumber);
                
                IceCream *iceCream = [[IceCream alloc] init];
                iceCream.identifier = a_i + 1;
                iceCream.price = currentNumber;
                
                [a addObject:iceCream];
            }
            
            //Sort input array.
            [a sortUsingComparator:^NSComparisonResult(IceCream *a, IceCream *b) {
                
                return [a compare:b];
            }];
            
            //Search sum.
            [IceCream modifiedSearch:a sum:m];
        }
    }
    
    return 0;
}
