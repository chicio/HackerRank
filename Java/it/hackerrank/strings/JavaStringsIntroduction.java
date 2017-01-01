package it.hackerrank.strings;
//
//  JavaStringsIntroduction.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 29/11/2016.
//
//  https://www.hackerrank.com/challenges/java-strings-introduction

import java.util.*;

public class JavaStringsIntroduction {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();
        sc.close();
        
        //Print sum of length.
        System.out.println(a.length() + b.length());
        
        //Are sorted?
        if (a.compareTo(b) > 0)  {
        	
        	System.out.println("Yes");
        } else {
        	
        	System.out.println("No");
        }
        
        //Capitalized print.
        System.out.println(a.substring(0, 1).toUpperCase() + a.substring(1, a.length()) + " " +
        				   b.substring(0, 1).toUpperCase() + b.substring(1, b.length()));
    }
}
