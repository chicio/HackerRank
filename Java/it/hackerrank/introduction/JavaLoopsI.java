//
//  JavaLoopsI.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 17/11/2016.
//
//  https://www.hackerrank.com/challenges/java-loops-i

package it.hackerrank.introduction;

import java.util.Scanner;

public class JavaLoopsI {

    public static void main(String[] args) {
    	
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();
        
        for (int i = 1; i <= 10; i++) {
        	
        	System.out.printf("%d x %d = %d \n", n, i, n * i);
        }
    }
}
