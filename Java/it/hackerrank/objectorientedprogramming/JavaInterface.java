package it.hackerrank.objectorientedprogramming;
//
//  JavaInterface.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-interface

import java.util.*;

interface AdvancedArithmetic {

	int divisor_sum(int n);
}

class MyCalculator implements AdvancedArithmetic {

	@Override
	public int divisor_sum(int n) {
	
		int sumDivisor = 0;
		
		for (int i = 1; i <= n; i++) {
			
			if (n % i == 0) {
				
				sumDivisor += i;
			}
		}
		
		return sumDivisor;
	}
}

public class JavaInterface {

	public static void main(String[] args) {
		
		MyCalculator my_calculator = new MyCalculator();
		System.out.print("I implemented: ");
		ImplementedInterfaceNames(my_calculator);
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.print(my_calculator.divisor_sum(n) + "\n");
		sc.close();
	}

	/*
	 * ImplementedInterfaceNames method takes an object and prints the name of
	 * the interfaces it implemented
	 */
	static void ImplementedInterfaceNames(Object o) {
		
		@SuppressWarnings("rawtypes")
		Class[] theInterfaces = o.getClass().getInterfaces();
		
		for (int i = 0; i < theInterfaces.length; i++) {
			
			String interfaceName = theInterfaces[i].getName();
			System.out.println(interfaceName);
		}
	}
}
