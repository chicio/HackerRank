//
//  JavaSubstring.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 09/12/2016.
//
//  https://www.hackerrank.com/challenges/java-string-reverse

import java.util.Scanner;

public class JavaStringReverse {

	public static void main(String[] args) {
		
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        sc.close();

        int startIndex = 0;
        int endIndex = a.length() - 1;
        
        String answer = "Yes";
        
        while (startIndex <= endIndex) {
        
        	if (a.charAt(startIndex) != a.charAt(endIndex)) {
        		
        		answer = "No";
        		break;
        	}
        	
        	startIndex++;
        	endIndex--;
        }
        
        System.out.println(answer);
	}
}
