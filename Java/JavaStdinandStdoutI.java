//
//  JavaStdinandStdoutI.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 31/10/2016.
//
//  https://www.hackerrank.com/challenges/java-stdin-and-stdout-1

import java.util.Scanner;

public class JavaStdinandStdoutI {

	public static void main(String[] args) {
		
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        scan.close();

        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
    }
}
