//
//  JavaBigInteger.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 29/12/2016.
//
//  https://www.hackerrank.com/challenges/java-biginteger

import java.math.BigInteger;
import java.util.Scanner;

public class JavaBigInteger {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		BigInteger a = sc.nextBigInteger();
		BigInteger b = sc.nextBigInteger();
		sc.close();
		
		BigInteger sum = a.add(b);
		BigInteger multiplication = a.multiply(b);
		
		System.out.println(sum);
		System.out.println(multiplication);
	}
}
