//
//  StacksBalancedBrackets.m
//  HackerRank
//
//  Created by Duroni Fabrizio on 02/11/2016.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Stack definition.

/*!
 Stack objective-c implementation.
 */
@interface Stack : NSObject

@property (nonatomic, strong) NSMutableArray *stackArray;

- (instancetype)init;
- (void)pushObject:(id)object;
- (id)popObject;
- (BOOL)isEmpty;

@end

@implementation Stack

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        
        self.stackArray = [NSMutableArray new];
    }
    
    return self;
}

- (void)pushObject:(id)object {
    
    [self.stackArray addObject:object];
}

- (id)popObject {
    
    if ([self isEmpty] == YES) {
        
        return nil;
    }
    
    id lastObject = [self.stackArray objectAtIndex: self.stackArray.count - 1];
    [self.stackArray removeLastObject];
    
    return lastObject;
}

- (BOOL)isEmpty {
    
    return self.stackArray.count == 0;
}

@end

int main(int argc, const char * argv[]){
    
    @autoreleasepool {
        
        int t;
        scanf("%i",&t);
        
        for(int a0 = 0; a0 < t; a0++) {
            
            NSString* expression;
            char* expression_temp = (char *)malloc(512000 * sizeof(char));
            scanf("%s",expression_temp);
            expression = [NSString stringWithFormat:@"%s", expression_temp];
            
            Stack *stackParenthesis = [[Stack alloc] init];
            
            NSString* result = @"YES";

            for (int i = 0; i < expression.length; i++) {
                
                NSString *currentParenthesis = [NSString stringWithFormat:@"%C", [expression characterAtIndex:i]];
                
                if ([currentParenthesis isEqualToString:@"{"] ||
                    [currentParenthesis isEqualToString:@"["] ||
                    [currentParenthesis isEqualToString:@"("]) {
                    
                    [stackParenthesis pushObject:currentParenthesis];
                } else {
                    
                    NSString *lastParenthesis =  [stackParenthesis popObject];
                    
                    if (lastParenthesis == nil) {
                        
                        result = @"NO";
                        break;
                    }
                    
                    if ([lastParenthesis isEqualToString:@"("] == YES &&
                        [currentParenthesis isEqualToString:@")"] == NO) {
                        
                        result = @"NO";
                        break;
                    }
                    
                    if ([lastParenthesis isEqualToString:@"["] == YES &&
                        [currentParenthesis isEqualToString:@"]"] == NO) {
                        
                        result = @"NO";
                        break;
                    }
                    
                    if ([lastParenthesis isEqualToString:@"{"] == YES &&
                        [currentParenthesis isEqualToString:@"}"] == NO) {
                        
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
