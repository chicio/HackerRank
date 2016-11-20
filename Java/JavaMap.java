//
//  JavaMap.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 20/11/2016.
//
//  https://www.hackerrank.com/challenges/phone-book

import java.util.HashMap;
import java.util.Scanner;

public class JavaMap {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		//n is number of phone book entries.
		int n = sc.nextInt();
	    sc.nextLine();

		HashMap<String, String> phoneBook = new HashMap<String, String>();
		
		for (int i = 0; i < n; i++) {
			
			String name = sc.nextLine();
			String number = sc.next();
	        sc.nextLine();
			
			phoneBook.put(name, number);
		}
		
		while (sc.hasNext()) {
			
			String query = sc.nextLine();
			String result = phoneBook.get(query);
			
			if (result == null) {
				
				System.out.println("Not found");
			} else {
				
				System.out.println(query + "=" + result);
			}
		}
		
		sc.close();
	}
}
