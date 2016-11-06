//
//  TriesContacts.m
//  HackerRank
//
//  Created by Fabrizio Duroni on 06/11/2016.
//
//  https://www.hackerrank.com/challenges/ctci-contacts

#import <Foundation/Foundation.h>

//******** Trie node definition ********//

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct TrieNode {
  
    struct TrieNode *children[ALPHABET_SIZE];
    bool isCompleteWord;
    unichar letter;
} TrieNode;

TrieNode *createNode() {

    TrieNode *newNode = (TrieNode *)malloc(sizeof(TrieNode));
    
    if (newNode) {
        
        newNode->isCompleteWord = false;
        
        //Clear children array.
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            
            newNode->children[i] = NULL;
        }
    }
    
    return newNode;
}


//******** Trie definition ********//

//Public interface
@interface Trie : NSObject

- (instancetype)init;
- (void)insert:(NSString *)word;
- (bool)searchWord:(NSString *)word;
- (int)countWordsForPartial:(NSString *)word;

@end

//Private interface
@interface Trie () {

    TrieNode *root;
}

- (int)countWords:(TrieNode *)node;

@end

//Implementation
@implementation Trie

- (instancetype)init {
    
    self = [super init];
    
    if (self) {

        //Init root.
        root = createNode();
    }
    
    return self;
}
    
- (void)insert:(NSString *)word {
    
    int index = 0;
    
    TrieNode *currentNode = root;
    
    for (int i = 0; i < word.length; i++) {
        
        index = CHAR_TO_INDEX([word characterAtIndex:i]);
        
        if (!currentNode->children[index]) {
            
            currentNode->children[index] = createNode();
            currentNode->children[index]->letter = [word characterAtIndex:i];
        }
        
        currentNode = currentNode->children[index];
    }
    
    currentNode->isCompleteWord = true;
}

- (bool)searchWord:(NSString *)word {

    int index;
    
    TrieNode *currentNode = root;
    
    for (int i = 0; i < word.length; i++) {
     
        index = CHAR_TO_INDEX([word characterAtIndex:i]);
        
        if (currentNode->children[index] == NULL) {
            
            return false;
        }
        
        currentNode = currentNode->children[index];
    }
    
    return currentNode && currentNode->isCompleteWord;
}

- (int)countWordsForPartial:(NSString *)word {
 
    int index;
    
    TrieNode *currentNode = root;
    
    for (int i = 0; i < word.length; i++) {
        
        index = CHAR_TO_INDEX([word characterAtIndex:i]);
        
        if (currentNode->children[index] == NULL) {
            
            return false;
        }
        
        currentNode = currentNode->children[index];
    }

    int countOfWords = [self countWords:currentNode];
    
    return countOfWords;
}

- (int)countWords:(TrieNode *)node {
    
    int sum = 0;

    if (node->isCompleteWord) {
     
        sum = 1;
    }
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        
        if (node->children[i]) {
            
            sum = sum + [self countWords:node->children[i]];
        }
    }
    
    return sum;
}

@end


//******** Main ********//

int main(int argc, const char * argv[]) {
    
    @autoreleasepool{
        
        int n;
        scanf("%i", &n);
        
        Trie* trie = [[Trie alloc] init];
        
        for (int a0 = 0; a0 < n; a0++) {
            
            NSString* op;
            char* op_temp = (char *)malloc(512000 * sizeof(char));
            NSString* contact;
            char* contact_temp = (char *)malloc(512000 * sizeof(char));
            
            scanf("%s %s", op_temp, contact_temp);
            
            op = [NSString stringWithFormat:@"%s", op_temp];
            contact = [NSString stringWithFormat:@"%s", contact_temp];
            
            if ([op isEqualToString:@"add"]) {
                
                [trie insert:contact];
            } else {
                
                printf("%d\n", [trie countWordsForPartial:contact]);
            }
        }
    }
    
    return 0;
}
