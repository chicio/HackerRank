//
//  MaximumElement.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 22/12/2016.
//
//  https://www.hackerrank.com/challenges/maximum-element

#import <Foundation/Foundation.h>

//******** Stack definition ********//

@interface Stack : NSObject

/*!
 Add element to the stack.
 
 @param element element to be added.
 */
- (void)push:(id)element;

/*!
 Pop element from the stack.
 
 @returns the element popped.
 */
- (id)pop;

/*!
 Get peek stack element.
 
 @returns the peek element.
 */
- (id)peek;

@end

@interface Stack()

/// Stack array.
@property (nonatomic, strong) NSMutableArray *stackArray;

@end

@implementation Stack

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        
        self.stackArray = [[NSMutableArray alloc] init];
    }
    
    return self;
}

- (void)push:(id)element {
    
    if (element) {

        [self.stackArray addObject:element];
    }
}

- (id)pop {
    
    id object = [self.stackArray lastObject];
    [self.stackArray removeLastObject];
    
    return object;
}

- (id)peek {
    
    return [self.stackArray lastObject];
}

@end


//******** Stack Extension with max definition ********//

@interface StackWithMax : Stack

/*!
 Get current max element of the stack.
 
 @returns current max of the stack.
 */
- (id)max;

@end

@interface StackWithMax()

/// Stack Max element (stored in order).
@property (nonatomic, strong) Stack *stackMax;

@end

@implementation StackWithMax

- (instancetype)init {
 
    self = [super init];
    
    if (self) {
        
        self.stackMax = [[Stack alloc] init];
    }
    
    return self;
}

- (void)push:(id)element {
    
    if (element) {
        
        [self.stackArray addObject:element];
    }
    
    if (![self.stackMax peek] ||
        [element isGreaterThan:[self.stackMax peek]] ||
        [element isEqualTo:[self.stackMax peek]]) {
        
        [self.stackMax push:element];
    }
}

- (id)pop {
    
    id element = [self.stackArray lastObject];
    [self.stackArray removeLastObject];
    
    if ([self.stackMax peek] && [element isEqualTo:[self.stackMax peek]]) {
        
        [self.stackMax pop];
    }
    
    return element;
}

- (id)max {
 
    if ([[self.stackMax peek] isEqualTo:[NSNumber numberWithInt:0]]) {
        
        NSLog(@"");
    }
    
    return [self.stackMax peek];
}

@end


//******** Main ********//

int main(int argc, const char * argv[]){
    
    @autoreleasepool {
        
        int numberOfOperation;
        scanf("%i", &numberOfOperation);

        StackWithMax *stack = [[StackWithMax alloc] init];
        
        for (int i = 0; i < numberOfOperation; i++) {
            
            int operation;
            scanf("%i", &operation);

            switch (operation) {
                case 1: {
                    int value;
                    scanf("%i", &value);
                    [stack push:[NSNumber numberWithInt:value]];
                    break;
                }
                case 2: {
                    [stack pop];
                    break;
                }
                case 3: {
                    printf("%i \n", [[stack max] intValue]);
                    break;
                }
                default:
                    break;
            }
        }
        
    }
    
    return 0;
}
