//
//  QueuesATaleofTwoStacks.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 03/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks

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


//******** Queue definition ********//

//Public interface.
@interface Queue : NSObject

- (void)enqueue:(id)object;
- (id)dequeue;
- (id)front;

@end

//Private interface.
@interface Queue ()

/// Input stack.
@property (nonatomic, strong) Stack *inputStack;
/// Output stack.
@property (nonatomic, strong) Stack *outputStack;

@end

//Implementation.
@implementation Queue

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        
        self.inputStack = [[Stack alloc] init];
        self.outputStack = [[Stack alloc] init];
    }
    
    return self;
}

- (void)enqueue:(id)object {
    
    [self.inputStack push:object];
}

- (id)dequeue {
    
    if ([self.inputStack isEmpty] == YES && [self.outputStack isEmpty] == YES) {
        
        //Both empty, so no elements: return nil.
        return nil;
    }
    
    //Update stacks.
    [self moveObjectsBetweenStacks];
    
    //Return front element AND removing it.
    return [self.outputStack pop];
}

- (id)front {
    
    if ([self.inputStack isEmpty] == YES && [self.outputStack isEmpty] == YES) {
        
        //Both empty, so no elements: return nil.
        return nil;
    }
    
    //Update stacks.
    [self moveObjectsBetweenStacks];
    
    //Return front element WITHOUT removing it.
    return [self.outputStack peek];
}

- (void)moveObjectsBetweenStacks {
    
    //If output stack is empty, push into it everything from input stack.
    if ([self.outputStack isEmpty] == YES) {
        
        while ([self.inputStack isEmpty] == NO) {
            
            [self.outputStack push:[self.inputStack pop]];
        }
    }
}

@end


//******** Main ********//

int main(int argc, const char * argv[]) {
    
    @autoreleasepool {
        
        //read number of queries.
        int t;
        scanf("%i", &t);
        
        int type;
        int value = 0;
        
        //Create queue.
        Queue *queue = [[Queue alloc] init];
        
        for (int a0 = 0; a0 < t; a0++) {
            
            //Get query type.
            scanf("%d", &type);
            
            switch (type) {
                    
                case 1: {
                    
                    //Get query value.
                    scanf("%d", &value);
                    
                    //Enqueue new value.
                    [queue enqueue:[NSNumber numberWithInt:value]];
                }
                    break;
                case 2: {
                    
                    //Dequeue.
                    [queue dequeue];
                }
                    break;
                case 3: {
                    
                    //Constraints guarantee that there's always a front
                    //when there's a query of type 3 (so no safety check).
                    printf("%d\n", [[queue front] intValue]);
                }
                    break;
            }
        }
    }
    
    return 0;
}
