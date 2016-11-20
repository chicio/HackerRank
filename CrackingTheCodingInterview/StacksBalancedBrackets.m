//
//  StacksBalancedBrackets.m
//  HackerRank
//
//  Created by Duroni Fabrizio on 02/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-balanced-brackets

#import <Foundation/Foundation.h>

//******** Stack definition ********//

//Public interface.
@interface Stack : NSObject

- (instancetype)init;
- (void)push:(id)object;
- (id)pop;
- (BOOL)isEmpty;
- (id)peek;

@end

//Private interface.
@interface Stack ()

/// Array data structure used as stack.
@property (nonatomic, strong) NSMutableArray *stackArray;

@end

//Implementation.
@implementation Stack

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        
        self.stackArray = [NSMutableArray new];
    }
    
    return self;
}

- (void)push:(id)object {
    
    [self.stackArray addObject:object];
}

- (id)pop {
    
    if ([self isEmpty] == YES) {
        
        return nil;
    }
    
    id lastObject = [self.stackArray lastObject];
    [self.stackArray removeLastObject];
    
    return lastObject;
}

- (BOOL)isEmpty {
    
    return self.stackArray.count == 0;
}

- (id)peek {
    
    id lastObject = [self.stackArray lastObject];
    
    return lastObject;
}

@end


//******** Main ********//

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
