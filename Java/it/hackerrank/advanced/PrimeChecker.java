//
//  PrimeChecker.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 09/12/2016.
//
//  https://www.hackerrank.com/challenges/prime-checker

package it.hackerrank.advanced;

import java.io.*;
import java.util.*;
import java.lang.reflect.*;

class Prime {

	public boolean isPrime(int number) {
	    
	    if (number <= 1) {
	        
	        return false;
	    }
	    
	    if (number == 2) {
	        
	        return true;
	    }
	    
	    for (int i = 2; i <= Math.sqrt(number); i++) {
	        
	        if (number % i == 0) {
	            
	            return false;
	        }
	    }
	    
	    return true;
	}
	
	public void checkPrime(int... numbers) {

		for (int number : numbers) {

			if (isPrime(number)) {
				
				System.out.print(number + " ");
			}
		}
		
		System.out.println();
	}
}

public class PrimeChecker {

	public static void main(String[] args) {
		try {

			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int n1 = Integer.parseInt(br.readLine());
			int n2 = Integer.parseInt(br.readLine());
			int n3 = Integer.parseInt(br.readLine());
			int n4 = Integer.parseInt(br.readLine());
			int n5 = Integer.parseInt(br.readLine());
			Prime ob = new Prime();
			ob.checkPrime(n1);
			ob.checkPrime(n1, n2);
			ob.checkPrime(n1, n2, n3);
			ob.checkPrime(n1, n2, n3, n4, n5);
			Method[] methods = Prime.class.getDeclaredMethods();
			Set<String> set = new HashSet<>();
			boolean overload = false;

			for (int i = 0; i < methods.length; i++) {

				if (set.contains(methods[i].getName())) {

					overload = true;
					break;
				}

				set.add(methods[i].getName());
			}

			if (overload) {

				throw new Exception("Overloading not allowed");
			}
		} catch (Exception e) {

			System.out.println(e);
		}
	}
}
