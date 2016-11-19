//
//  JavaIntToString.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 18/11/2016.
//
//  https://www.hackerrank.com/challenges/java-int-to-string

import java.util.*;

public class JavaIntToString {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		in.close();
		
		String s = String.valueOf(n);

		if (n == Integer.parseInt(s)) {
			
			System.out.println("Good job");
		} else {
			
			System.out.println("Wrong answer.");
		}
	}
}
