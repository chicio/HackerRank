package it.hackerrank.strings;
//
//  JavaSubstring.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 09/12/2016.
//
//  https://www.hackerrank.com/challenges/java-anagrams

import java.util.Scanner;

public class JavaAnagrams {

	static boolean isAnagram(String a, String b) {

		if (a.length() != b.length()) {
			
			//Different length: no anagram.
			return false;
		}
		
		final int alphabetSize = 26;
		int[] aLetters = new int[alphabetSize];
		int[] bLetters = new int[alphabetSize];
		
		for (int i = 0; i < a.length(); i++) {
			
			aLetters[Character.toLowerCase(a.charAt(i)) - 'a']++;
			bLetters[Character.toLowerCase(b.charAt(i)) - 'a']++;
		}
		
		for (int i = 0; i < alphabetSize; i++) {

			if (aLetters[i] - bLetters[i] != 0) {
				
				return false;
			}
		}
		
		return true;
    }

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		String a = scan.next();
		String b = scan.next();
		scan.close();
		boolean ret = isAnagram(a, b);
		System.out.println((ret) ? "Anagrams" : "Not Anagrams");
	}
}
