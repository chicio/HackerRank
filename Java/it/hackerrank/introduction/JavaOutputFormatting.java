//
//  JavaOutputFormatting.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/10/2016.
//
//  https://www.hackerrank.com/challenges/java-output-formatting

package it.hackerrank.introduction;

import java.util.Scanner;

public class JavaOutputFormatting {

	public static void main(String[] args) {
		
        Scanner sc = new Scanner(System.in);
        System.out.println("================================");
        
        for (int i = 0 ; i < 3; i++) { 
        	
            String s1 = sc.next();
            int x = sc.nextInt();
            
            System.out.printf("%-15s%03d %n", s1, x);        
        }
        
        System.out.println("================================");		
        
        sc.close();
	}
}
