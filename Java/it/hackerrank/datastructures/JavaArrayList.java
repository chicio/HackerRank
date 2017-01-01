//
//  JavaArrayList.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-arraylist

package it.hackerrank.datastructures;

import java.util.ArrayList;
import java.util.Scanner;

public class JavaArrayList {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int rows = sc.nextInt();
		
		ArrayList<ArrayList<Integer>> rowList = new ArrayList<ArrayList<Integer>>(rows);
		
		//Fill arraylist.
		for (int i = 0; i < rows; i++) {
			
			int elementsCount = sc.nextInt();
			
			rowList.add(new ArrayList<Integer>(elementsCount));
			
			for (int k = 0; k < elementsCount; k++) {
				
				int newElement = sc.nextInt();
				rowList.get(i).add(newElement);
			} 
		}
		
		//Queries.
		int queries = sc.nextInt();
		
		for (int i = 0; i < queries; i++) {

			int x = sc.nextInt() - 1;
			int y = sc.nextInt() - 1;
			
			if (rowList.size() > x && rowList.get(x).size() > y) {
				
				System.out.println(rowList.get(x).get(y));
			} else {
				
				System.out.println("ERROR!");
			}
		}
		
		sc.close();
	}
}
