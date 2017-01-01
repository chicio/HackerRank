//
//  JavaStack.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 20/11/2016.
//
//  https://www.hackerrank.com/challenges/java-stack

package it.hackerrank.datastructures;

import java.util.Scanner;
import java.util.Stack;

public class JavaStack {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		while (sc.hasNext()) {

			String input = sc.next();
			String result = "true";
			Stack<Character> stackParenthesis = new Stack<Character>();

			for (int i = 0; i < input.length(); i++) {

				Character currentChar = input.charAt(i);

				if (currentChar.charValue() == '(' || 
					currentChar.charValue() == '[' || 
					currentChar.charValue() == '{') {

					stackParenthesis.push(currentChar);
				} else {

					if (stackParenthesis.size() == 0) {

						result = "false";
						break;
					} else {

						Character lastParenthesis = stackParenthesis.pop();

						if (lastParenthesis.charValue() == '(' && 
							!(currentChar.charValue() == ')')) {

							result = "false";
							break;
						}

						if (lastParenthesis.charValue() == '[' &&
							!(currentChar.charValue() == ']')) {

							result = "false";
							break;
						}

						if (lastParenthesis.charValue() == '{'  && 
							!(currentChar.charValue() == '}')) {

							result = "false";
							break;
						}
					}
				}
			}

			if (!stackParenthesis.empty()) {

				result = "false";
			}

			System.out.println(result);
		}

		sc.close();
	}
}
