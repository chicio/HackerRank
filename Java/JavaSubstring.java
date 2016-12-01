//
//  JavaSubstring.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 01/12/2016.
//
//  https://www.hackerrank.com/challenges/java-substring

import java.util.Scanner;

public class JavaSubstring {

	public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        String s = in.next();
        int start = in.nextInt();
        int end = in.nextInt();
        in.close();
        
        System.out.println(s.substring(start, end));
	}
}
