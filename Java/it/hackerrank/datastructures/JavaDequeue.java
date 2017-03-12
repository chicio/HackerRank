//
//  JavaDequeue.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 12/03/2017.
//
//  https://www.hackerrank.com/challenges/java-dequeue

package it.hackerrank.datastructures;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class JavaDequeue {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		Deque<Integer> deque = new ArrayDeque<>();
	    Set<Integer> set = new HashSet<Integer>();
	    
		int n = in.nextInt();
		int m = in.nextInt();
		int maxUnique = 0;
		int lastElement = 0;

		for (int i = 0; i < n; i++) {

			int num = in.nextInt();
			deque.addFirst(num);
			set.add(num);

			if (deque.size() == m) {
				
				if (!deque.contains(lastElement)) {
					
					set.remove(lastElement);
				}
								
				int setSize = set.size();
				
				if (maxUnique < setSize) {
					
					maxUnique = setSize;
				}
				
				lastElement = deque.removeLast();
			}
		}

		System.out.println(maxUnique);
		in.close();
	}
}
