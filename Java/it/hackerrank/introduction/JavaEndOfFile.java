//
//  JavaEndOfFile.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 17/11/2016.
//
//  https://www.hackerrank.com/challenges/java-end-of-file

package it.hackerrank.introduction;

import java.util.Scanner;

public class JavaEndOfFile {

	public static void main(String[] args) {
		
        Scanner sc = new Scanner(System.in);
        
        String rowContent;
        int rowNumber = 1;
        
        while (sc.hasNext()) {
        	
        	rowContent = sc.nextLine();
        	System.out.println(rowNumber + " " + rowContent);
        	rowNumber++;
        }
        
        sc.close();
	}
}
