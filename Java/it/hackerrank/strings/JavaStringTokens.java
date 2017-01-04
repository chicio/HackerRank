//
//  JavaStringTokens.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 04/01/2017.
//
//  https://www.hackerrank.com/challenges/java-string-tokens

package it.hackerrank.strings;

import java.util.Scanner;

public class JavaStringTokens {

	public static void main(String[] args) {
		
        Scanner scan = new Scanner(System.in);
        
        if (!scan.hasNext()) { 
            
            System.out.print(0);
            return;
        }

        String s = scan.nextLine();
        scan.close();

		String[] split = s.trim().split("[!,?.*_'@\\ ]+");
			
		System.out.println(split.length);
			
		for (int i = 0; i < split.length; i++) {
			
		      System.out.println(split[i]);
		}
	}
}
