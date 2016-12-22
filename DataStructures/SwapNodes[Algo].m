//
//  SwapNodes[Algo].m
//  HackerRank
//
//  Created by Fabrizio Duroni on 18/12/2016.
//
//  https://www.hackerrank.com/challenges/swap-nodes-algo

#import <Foundation/Foundation.h>

//******** Node definition ********//

@interface Node : NSObject

/// Data of the node.
@property (nonatomic, assign) int data;
/// Left node.
@property (nonatomic, strong) Node *left;
/// Right node.
@property (nonatomic, strong) Node *right;

/*!
 Constructor.
 
 @param data data of the node.
 
 @returns node instance.
 */
- (instancetype)initWithData:(int)data;

@end

@implementation Node

- (instancetype)initWithData:(int)data {
    
    self = [super init];
    
    if (self) {
        
        self.data = data;
    }
    
    return self;
}

@end


//******** Bynary Tree definition ********//

@interface BinaryTree : NSObject

/// Root of the binary tree.
@property (nonatomic, strong) Node* root;

/*!
 In order traversal.
 */
- (void)inOrderTraversal;

/*!
 Breadth search first modified to swap nodes at 
 specific level (level, 2 * levele, 3 * level...).
 
 @param level level of swaps.
 */
- (void)bfsWithSwapAtLevel:(int)level;

@end

@implementation BinaryTree

- (instancetype)init {
    
    self = [super init];
    
    if (self) {
        
        self.root = [[Node alloc] init];
        self.root.data = 1;
    }
    
    return self;
}

- (void)inOrder:(Node *)node {
    
    if (node.left) {
        
        [self inOrder:node.left];
    }
    
    printf("%i ", node.data);
    
    if (node.right) {
        
        [self inOrder:node.right];
    }
}

- (void)inOrderTraversal {
    
    [self inOrder:self.root];
    
    printf("\n");
}

- (void)swap:(NSMutableArray *)queue {
    
    for (Node *node in queue) {
        
        Node *temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}

- (void)bfsWithSwapAtLevel:(int)level {
    
    NSMutableArray<Node *> *queue = [[NSMutableArray alloc] init];
    [queue addObject:self.root];
    [queue addObject:[[Node alloc] initWithData:-1]];
    
    Node *currentNode;
    int depth = 1;
    
    if (level == 1) {
        
        [self swap:queue];
    }
    
    while (queue.count > 0) {
        
        currentNode = [queue firstObject];
        [queue removeObject:currentNode];
        
        if (currentNode.data != -1) {
            
            if (currentNode.left) {
                
                [queue addObject:currentNode.left];
            }
            
            if (currentNode.right) {
                
                [queue addObject:currentNode.right];
            }
        } else {
            
            depth++;
            
            if (depth % level == 0) {
                
                [self swap:queue];
            }
            
            if (queue.count > 0) {
                
                [queue addObject:currentNode];
            }
        }
    }
}

@end


//******** Main ********//

int main(int argc, const char * argv[]){
    
    @autoreleasepool {
        
        int numberOfNodes;
        scanf("%i", &numberOfNodes);
        
        BinaryTree* binaryTree = [[BinaryTree alloc] init];
        
        NSMutableDictionary<NSNumber *, Node *> *nodes = [[NSMutableDictionary alloc] init];
        [nodes setObject:binaryTree.root forKey:@1];
        
        Node *currentNode;
        
        for (int i = 1; i <= numberOfNodes; i++) {
            
            int left, right;
            scanf("%i %i", &left, &right);
            
            currentNode = [nodes objectForKey:[NSNumber numberWithInt:i]];
            
            if (currentNode) {
                
                if (left != -1) {
                    
                    currentNode.left = [[Node alloc] initWithData:left];
                    [nodes setObject:currentNode.left forKey:[NSNumber numberWithInt:currentNode.left.data]];
                }
                
                if (right != -1) {
                    
                    currentNode.right = [[Node alloc] initWithData:right];
                    [nodes setObject:currentNode.right forKey:[NSNumber numberWithInt:currentNode.right.data]];
                }
            }
        }
        
        int numberOfSwap;
        scanf("%i", &numberOfSwap);
        
        for (int i = 0; i < numberOfSwap; i++) {
            
            int depthForSwap;
            scanf("%i", &depthForSwap);
            
            [binaryTree bfsWithSwapAtLevel:depthForSwap];
            [binaryTree inOrderTraversal];
        }
    }
    
    return 0;
}
