package it.hackerrank.datastructures;

import java.util.Scanner;

public class Java1DArrayPart2 {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int n;
		int m;
		int[] array;
		
		for (int i  = 0; i < t; i++) {
			
			n = sc.nextInt();
			m = sc.nextInt();
			array = new int[n];
			boolean[] explored = new boolean[n];
			
			for (int h = 0; h < n; h++) {
				
				array[h] = sc.nextInt();
				explored[h] = false;
			}
			
			boolean gameFinished = false;
			boolean gameWin = false;
			int position = 0;
			
			while (!gameFinished) {
				
				if (position + m > array.length - 1 || position + 1 > array.length - 1) {
					
					gameFinished = true;
					gameWin = true;
				} else {
					
					explored[position] = true;
					
					if (!explored[position + m] && array[position + m] == 0) {
						
						position = position + m;
					} else if(!explored[position + 1] && array[position + 1] == 0) {
						
						position = position + 1;
					} else if(position - 1 >= 0 && !explored[position - 1] && array[position - 1] == 0) {
						
						position = position - 1;
					} else {
						
						gameFinished = true;
					}					
				}
			}
			
			if (gameWin) {
				
				System.out.println("YES");
			} else {
				
				System.out.println("NO");
			}
		}
		
		sc.close();
	}
}
