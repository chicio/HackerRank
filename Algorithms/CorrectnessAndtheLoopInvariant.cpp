//
//  CorrectnessAndtheLoopInvariant.cpp
//  HackerRank
//
//  Created by Duroni Fabrizio on 06/09/16.
//  Copyright © 2016 Fabrizio Duroni. All rights reserved.
//
//  https://www.hackerrank.com/challenges/correctness-invariant

#include <stdio.h>

/*
 Loop Invariant: remember "Modelli e Computazione" course during
 master degree at University Milano-Bicocca :)
 */
void insertionSort(int N, int arr[]) {
    
    int i,j;
    int value;
    
    for (i = 1 ; i < N; i++) {
        
        value=arr[i];
        j = i - 1;
        
        while (j>=0 && value<arr[j]) {
            
            arr[j+1]=arr[j];
            j=j-1;
        }
        
        arr[j+1]=value;
    }
    
    for (j=0;j<N;j++) {
        
        printf("%d",arr[j]);
        printf(" ");
    }
}

int main(void) {
    
    int N;
    
    scanf("%d", &N);
    
    int arr[N], i;

    for (i = 0; i < N; i++) {
    
        scanf("%d", &arr[i]);
    }
    
    insertionSort(N, arr);
    
    return 0;
}
