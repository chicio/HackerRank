//
//  Java2DArray.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-2d-array

package it.hackerrank.datastructures;

import java.util.Scanner;

public class Java2DArray {

    public static void main(String[] args) {
    	
        Scanner in = new Scanner(System.in);
        
        int arr[][] = new int[6][6];
        
        for (int i = 0; i < 6; i++) {
        	
            for (int j = 0; j < 6; j++) {
            	
                arr[i][j] = in.nextInt();
            }
        }
        
        in.close();
        
        int maxSum = 0;
        int currentSum = 0;

        for (int i = 0; i < 4; i++) {
            
            for (int k = 0; k < 4; k++) {
                
                currentSum = arr[i][k] + arr[i][k + 1] + arr[i][k + 2];
                currentSum += arr[i + 1][k + 1];
                currentSum += arr[i + 2][k] + arr[i + 2][k + 1] + arr[i + 2][k + 2];
                
                if(currentSum > maxSum || (i == 0 && k == 0)) {
                    
                    maxSum = currentSum;
                }
            }
        }
        
        System.out.println(maxSum);
    }	
}
