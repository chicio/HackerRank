//
//  JavaHashset.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 21/02/2017.
//
//  https://www.hackerrank.com/challenges/java-hashset

package it.hackerrank.datastructures;

import java.util.HashSet;
import java.util.Scanner;

public class JavaHashset {

	public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        String[] pair_left = new String[t];
        String[] pair_right = new String[t];
        
        for (int i = 0; i < t; i++) {
        	
            pair_left[i] = s.next();
            pair_right[i] = s.next();
        }
        
        s.close();
        
        HashSet<String> pairSet = new HashSet<String>();
        
        for (int i = 0; i < t; i++) {
        	
        	pairSet.add("(" + pair_left[i] + "," + pair_right[i] + ")");
        	System.out.println(pairSet.size());
        }
	}
}
