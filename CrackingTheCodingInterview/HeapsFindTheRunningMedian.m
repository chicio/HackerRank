//
//  HeapsFindTheRunningMedian.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 03/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-find-the-running-median

#import <Foundation/Foundation.h>

//******** Heap definition ********//

//Public interface.
@interface Heap : NSObject

- (int)getLeftChildIndex:(int)parentIndex;
- (int)getRightChildIndex:(int)parentIndex;
- (int)getParentIndex:(int)childIndex;
- (BOOL)hasLeftChild:(int)index;
- (BOOL)hasRightChild:(int)index;
- (BOOL)hasParent:(int)index;
- (id)leftChild:(int)index;
- (id)rightChild:(int)index;
- (id)parent:(int)index;
- (id)peek;
- (BOOL)isEmpty;
- (id)poll;
- (void)add:(id)object;
- (void)heapifyDown;
- (void)heapifyUp;
- (int)heapSize;

@end

//Private interface.
@interface Heap ()

/// Size of the heap.
@property (nonatomic, assign) int size;
/// Array that represents the heap elements.
@property (nonatomic, strong) NSMutableArray *items;

@end

//Implementation.
@implementation Heap

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        
        self.size = 0;
        self.items = [[NSMutableArray alloc] init];
    }
    
    return self;
}

- (int)getLeftChildIndex:(int)parentIndex {
    
    return 2 * parentIndex + 1;
}

- (int)getRightChildIndex:(int)parentIndex {
    
    return 2 * parentIndex + 2;
}

- (int)getParentIndex:(int)childIndex {
    
    return (childIndex - 1) / 2;
}

- (BOOL)hasLeftChild:(int)index {
    
    return [self getLeftChildIndex:index] < self.size;
}

- (BOOL)hasRightChild:(int)index {
    
    return [self getRightChildIndex:index] < self.size;
}

- (BOOL)hasParent:(int)index {
    
    return [self getParentIndex:index] >= 0;
}

- (id)leftChild:(int)index {
    
    return self.items[[self getLeftChildIndex:index]];
}

- (id)rightChild:(int)index {
    
    return self.items[[self getRightChildIndex:index]];
}

- (id)parent:(int)index {
    
    return self.items[[self getParentIndex:index]];
}

- (id)peek {
    
    if ([self isEmpty] == YES) {
        
        return nil;
    }
    
    return self.items[0];
}

- (BOOL)isEmpty {
    
    return self.items.count == 0;
}

- (id)poll {
    
    if ([self isEmpty] == YES) {
        
        return nil;
    }
    
    id item = self.items[0];
    self.items[0] = self.items[self.size - 1];
    [self.items removeLastObject];
    self.size--;
    
    //Reorganize items in array.
    [self heapifyDown];
    
    return item;
}

- (void)add:(id)object {
    
    [self.items addObject:object];
    self.size++;
    
    [self heapifyUp];
}

- (void)heapifyDown {
    
    NSAssert(NO, @"Must be implemented in subclasses");
}

- (void)heapifyUp {
    
    NSAssert(NO, @"Must be implemented in subclasses");
}

- (int)heapSize {
    
    return self.size;
}

@end


//******** MaxHeap definition ********//

//Public interface.
@interface MaxHeap : Heap

@end

//Implementation.
@implementation MaxHeap

- (void)heapifyDown {
    
    int index = 0;
    
    while ([self hasLeftChild:index] == YES) {
        
        int smallerChildIndex = [self getLeftChildIndex:index];
        
        if ([self hasRightChild:index] == YES && [[self rightChild:index] isGreaterThan:[self leftChild:index]]) {
            
            smallerChildIndex = [self getRightChildIndex:index];
        }
        
        if ([self.items[index] isGreaterThan:self.items[smallerChildIndex]]) {
            
            break;
        } else {
            
            [self.items exchangeObjectAtIndex:index withObjectAtIndex:smallerChildIndex];
        }
        
        index = smallerChildIndex;
    }
}

- (void)heapifyUp {
    
    int index = self.size - 1;
    
    while ([self hasParent:index] == YES && [[self parent:index] isLessThan:self.items[index]]) {
        
        [self.items exchangeObjectAtIndex:[self getParentIndex:index] withObjectAtIndex:index];
        index = [self getParentIndex:index];
    }
}

@end


//******** MinHeap definition ********//

//Public interface.
@interface MinHeap : Heap

@end

//Implementation.
@implementation MinHeap

- (void)heapifyDown {
    
    int index = 0;
    
    while ([self hasLeftChild:index] == YES) {
        
        int smallerChildIndex = [self getLeftChildIndex:index];
        
        if ([self hasRightChild:index] == YES && [[self rightChild:index] isLessThan:[self leftChild:index]]) {
            
            smallerChildIndex = [self getRightChildIndex:index];
        }
        
        if ([self.items[index] isLessThan:self.items[smallerChildIndex]]) {
            
            break;
        } else {
            
            [self.items exchangeObjectAtIndex:index withObjectAtIndex:smallerChildIndex];
        }
        
        index = smallerChildIndex;
    }
}

- (void)heapifyUp {
    
    int index = self.size - 1;
    
    while ([self hasParent:index] == YES && [[self parent:index] isGreaterThan:self.items[index]]) {
        
        [self.items exchangeObjectAtIndex:[self getParentIndex:index] withObjectAtIndex:index];
        index = [self getParentIndex:index];
    }
}

@end


//******** Main ********//

/*!
 Get median of a stream of integer.
 The method maintain a left max heap and a right min heap.
 In this way the root nodes of the two heaps are the 
 
 @param newElement new element to be inserted.
 @param currentMedian the current median.
 @param leftHeap left heap with values LESS than current median. It is a MaxHeap, so its root is first of two medians value.
 @param leftHeap left heap with values GREATER than current median. It is a MixHeap, so its root is second of two medians value.
 
 @returns the new median.
 */
double getMedian(NSNumber *newElement, double currentMedian, MaxHeap *leftHeap, MinHeap *rightHeap) {
    
    if ([leftHeap heapSize] > [rightHeap heapSize]) {
        
        if([newElement doubleValue] < currentMedian) {
        
            //To rebalance the heaps we move
            //the root of the min heap into max heap (will become root)
            //and we add the new element into max heap.
            [rightHeap add:[leftHeap poll]];
            [leftHeap add:newElement];
        } else {
            
            //Easy rebalancing: add to right.
            [rightHeap add:newElement];
        }
        
        currentMedian = ([[leftHeap peek] doubleValue] + [[rightHeap peek] doubleValue]) / 2.0;
    } else if ([leftHeap heapSize] == [rightHeap heapSize]) {
        
        if([newElement doubleValue] < currentMedian) {
            
            [leftHeap add:newElement];
            currentMedian = [[leftHeap peek] doubleValue];
        } else {
            
            [rightHeap add:newElement];
            currentMedian = [[rightHeap peek] doubleValue];
        }
    } else {
        
        if([newElement doubleValue] < currentMedian) {
            
            //Easy rebalancing: add to left.
            [leftHeap add:newElement];
        } else {
            
            //To rebalance the heaps we move
            //the root of the max heap into min heap (will become root)
            //and we add the new element into min heap.
            [leftHeap add:[rightHeap poll]];
            [rightHeap add:newElement];
        }
        
        currentMedian = ([[leftHeap peek] doubleValue] + [[rightHeap peek] doubleValue]) / 2.0;
    }
    
    // No need to return, m already updated
    return currentMedian;
}


//******** Main ********//

int main(int argc, const char * argv[]) {
    
    @autoreleasepool {
        
        int n;
        scanf("%i",&n);
        int a[n];
        
        double median = 0;
        MaxHeap *maxHeap = [[MaxHeap alloc] init];
        MinHeap *minHeap = [[MinHeap alloc] init];
        
        for (int a_i = 0; a_i < n; a_i++) {
            
            scanf("%d",&a[a_i]);
            
            median = getMedian([NSNumber numberWithInt:a[a_i]], median, maxHeap, minHeap);
            
            printf("%.1f\n", median);
        }
    }
    
    return 0;
}
