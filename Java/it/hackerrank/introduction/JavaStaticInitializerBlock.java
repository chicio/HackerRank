//
//  JavaStaticInitializerBlock.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 18/11/2016.
//
//  https://www.hackerrank.com/challenges/java-static-initializer-block

package it.hackerrank.introduction;

import java.util.Scanner;

public class JavaStaticInitializerBlock {

	/// Flag used to alter main execution. 
	static Boolean flag;
	/// Breadth.
	static int B;
	/// Height.
	static int H;
	
	/// A static initializer block.
	static {
		
		Scanner sc = new Scanner(System.in);
		
		flag = true;
		B = sc.nextInt();
		H = sc.nextInt();
		
		sc.close();
		
		if (B <= 0 || H <= 0) {
			
			flag = false;
			System.out.println("java.lang.Exception: Breadth and height must be positive");
		}
	}
	
	public static void main(String[] args) {
		
		if (flag) {
			
			int area = B * H;
			
			System.out.print(area);
		}	
	}
}
