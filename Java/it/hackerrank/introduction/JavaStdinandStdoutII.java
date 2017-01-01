//
//  JavaStdinandStdoutII.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/10/2016.
//
//  https://www.hackerrank.com/challenges/java-stdin-stdout

package it.hackerrank.introduction;

import java.util.Scanner;

public class JavaStdinandStdoutII {

	public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int i = scan.nextInt();
        double d = scan.nextDouble();
        scan.nextLine();
        String s = scan.nextLine();
        scan.close();

        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
	}
}
