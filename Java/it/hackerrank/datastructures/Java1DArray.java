//
//  Java1DArray.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-1d-array-introduction

package it.hackerrank.datastructures;

import java.util.Scanner;

public class Java1DArray {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        // Declare array a here
        int a[] = new int[n];

        for (int i = 0 ; i < n; i++) {
            
            int val = scan.nextInt();
            a[i] = val;
        }
        
        scan.close();

        // Prints each sequential element in array a
        for (int i = 0; i < a.length; i++) {
        	
            System.out.println(a[i]);
        }        
    }
}
