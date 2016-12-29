//
//  BalancedBrackets.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 23/12/2016.
//  
//  https://www.hackerrank.com/challenges/balanced-brackets

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

/*!
 Check if the stack is empty.
 
 @returns true if the stack is empty, else false.
 */
- (BOOL)isEmpty;

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

- (BOOL)isEmpty {
    
    return self.stackArray.count == 0;
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
        
        int t;
        scanf("%i", &t);
        
        for(int a0 = 0; a0 < t; a0++) {
            
            NSString* expression;
            char* expression_temp = (char *)malloc(512000 * sizeof(char));
            scanf("%s", expression_temp);
            expression = [NSString stringWithFormat:@"%s", expression_temp];
            
            Stack *stackParenthesis = [[Stack alloc] init];
            
            NSString* result = @"YES";
            
            for (int i = 0; i < expression.length; i++) {
                
                NSString *currentParenthesis = [NSString stringWithFormat:@"%C", [expression characterAtIndex:i]];
                
                if ([currentParenthesis isEqualToString:@"{"] ||
                    [currentParenthesis isEqualToString:@"["] ||
                    [currentParenthesis isEqualToString:@"("]) {
                    
                    [stackParenthesis push:currentParenthesis];
                } else {
                    
                    NSString *lastParenthesis =  [stackParenthesis pop];
                    
                    if (lastParenthesis == nil) {
                        
                        result = @"NO";
                        break;
                    }
                    
                    if ([lastParenthesis isEqualToString:@"("] &&
                        ![currentParenthesis isEqualToString:@")"]) {
                        
                        result = @"NO";
                        break;
                    }
                    
                    if ([lastParenthesis isEqualToString:@"["] &&
                        ![currentParenthesis isEqualToString:@"]"]) {
                        
                        result = @"NO";
                        break;
                    }
                    
                    if ([lastParenthesis isEqualToString:@"{"] &&
                        ![currentParenthesis isEqualToString:@"}"]) {
                        
                        result = @"NO";
                        break;
                    }
                }
            }
            
            if ([stackParenthesis isEmpty] == NO) {
                
                result = @"NO";
            }
            
            printf("%s\n", [result UTF8String]);
        }
    }
    
    return 0;
}
