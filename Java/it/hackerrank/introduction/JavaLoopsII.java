//
//  JavaLoopsII.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 17/11/2016.
//
//  https://www.hackerrank.com/challenges/java-loops

package it.hackerrank.introduction;

import java.util.Scanner;

public class JavaLoopsII {

    public static void main(String []argh) {
    	
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        
        for (int i = 0; i < t; i++) {
        	
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            
            int secondTermSerie = 0;
            
            for (int k = 0; k < n; k++) {
            	
            	secondTermSerie += (int)(Math.pow(2, k) * b);
            	System.out.printf("%d ", a + secondTermSerie);
            }
            
            System.out.println();
        }
        
        in.close();
    }
}
