package it.hackerrank.exceptionhandling;
//
//  JavaExceptionHandlingTryCatch.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 30/12/2016.
//
//  https://www.hackerrank.com/challenges/java-exception-handling-try-catch

import java.util.InputMismatchException;
import java.util.Scanner;

public class JavaExceptionHandlingTryCatch {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		try {
			
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			int result = a / b;
			
			System.out.println(result);
		} catch (ArithmeticException arithmethicException) {
			
			System.out.println("java.lang.ArithmeticException: / by zero");
		} catch (InputMismatchException inputException) {

			System.out.println("java.util.InputMismatchException");
		} finally {
			
			sc.close();
		}
	}
}
