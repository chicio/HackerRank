//
//  JavaList.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-list

package it.hackerrank.datastructures;

import java.util.ArrayList;
import java.util.Scanner;

public class JavaList {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		//n is number of elements in the list.
		int n = sc.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		
		for (int i = 0; i < n; i++) {
			
			list.add(sc.nextInt());
		}
		
		//q is number of elements in the list.
		int q = sc.nextInt();
		
		for (int i = 0; i < q; i++) {
			
			String operation = sc.next();
			
			if (operation.equals("Insert")) {
				
				//Index.
				int x = sc.nextInt();
				//Content.
				int y = sc.nextInt();
				
				list.add(x, y);
			}
			
			if (operation.equals("Delete")) {
				
				//Index.
				int x = sc.nextInt();
				
				list.remove(x);
			}
		}
		
		for (int k = 0; k < list.size(); k++) {
			
			System.out.printf("%d ", list.get(k));
		}
		
		sc.close();
	}
}
