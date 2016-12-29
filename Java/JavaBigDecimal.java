//
//  JavaBigDecimal.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 29/12/2016.
//
//  https://www.hackerrank.com/challenges/java-bigdecimal

import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class JavaBigDecimal {

	public static void main(String[] args) {
		
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String []s = new String[n + 2];
        
        for (int i = 0; i < n; i++) {
        	
            s[i] = sc.next();
        }
        
        sc.close();
        
        Arrays.sort(s, 0, n, new Comparator<String>() {
        	
            public int compare(String o1, String o2) {
            	
            	BigDecimal bd1 = new BigDecimal(o1);
            	BigDecimal bd2 = new BigDecimal(o2);
            	
            	return bd2.compareTo(bd1);
            }
        });
        
        //Output
        for(int i = 0; i < n; i++) {
        	
            System.out.println(s[i]);
        }
	}
}
