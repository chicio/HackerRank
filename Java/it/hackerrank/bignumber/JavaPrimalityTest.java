//
//  JavaPrimalityTest.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 29/12/2016.
//
//  https://www.hackerrank.com/challenges/java-primality-test

package it.hackerrank.bignumber;

import java.math.BigInteger;
import java.util.Scanner;

public class JavaPrimalityTest {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		BigInteger n = in.nextBigInteger();
		in.close();

		if (n.isProbablePrime(1)) {

			System.out.println("prime");
		} else {

			System.out.println("not prime");
		}
	}
}
