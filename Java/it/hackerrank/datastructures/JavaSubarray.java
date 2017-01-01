//
//  JavaSubarray.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 01/01/2017.
//
//  https://www.hackerrank.com/challenges/java-negative-subarray

package it.hackerrank.datastructures;

import java.util.Scanner;

public class JavaSubarray {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int[] array = new int[n];
		
		for (int i = 0; i < n; i++) {
			
			array[i] = sc.nextInt();
		}
		
		sc.close();
		
		int totalNegativeArray = 0;
		
	    for (int i = 0; i < array.length; i++) {
	    	
	        for (int j = i; j < array.length; j++) {
	        	
	        	int sum = 0;
	        	
	            for (int k = i; k <= j; k++) {
	            	
	                sum = sum + array[k]; 
	            }
	            
	            if (sum < 0) {
	            	
	            	totalNegativeArray++;
	            }
	        }
	    }
	    
	    System.out.println(totalNegativeArray);
	}
}
