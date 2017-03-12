//
//  Java1DArrayPart2.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 04/03/2017.
//
//  https://www.hackerrank.com/challenges/java-1d-array

package it.hackerrank.datastructures;

import java.util.Scanner;

/// Neeeded a little help with discussion.
public class Java1DArrayPart2 {
	
	public static boolean couldWin(int[] array, int currentPosition, int maxJump) {
		
		if (currentPosition >= array.length) {
			
			return true;
		}
		
		if (currentPosition < 0 || array[currentPosition] == 1) {
			
			return false;
		}
		
		array[currentPosition] = 1;
		
		return couldWin(array, currentPosition - 1, maxJump) || 
				couldWin(array, currentPosition + 1, maxJump) ||
				couldWin(array, currentPosition + maxJump, maxJump);
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int n;
		int m;
		int[] array;
		
		for (int i  = 0; i < t; i++) {
			
			n = sc.nextInt();
			m = sc.nextInt();
			array = new int[n];
			
			for (int h = 0; h < n; h++) {
				
				array[h] = sc.nextInt();
			}
			
			if (couldWin(array, 0, m)) {
				
				System.out.println("YES");
			} else {
				
				System.out.println("NO");
			}
		}
		
		sc.close();
	}
}
