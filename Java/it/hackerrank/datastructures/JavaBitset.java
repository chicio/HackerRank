//
//  JavaBitset.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 12/03/2017.
//
//  https://www.hackerrank.com/challenges/java-bitset

package it.hackerrank.datastructures;

import java.util.BitSet;
import java.util.HashMap;
import java.util.Scanner;

public class JavaBitset {

    public static void main(String[] args) {
    	
    	final int bitSetOneIdentifier = 1;
    	final int bitSetTwoIdentifier = 2;
    	
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
    	
    	HashMap<Integer, BitSet> bitsetMap = new HashMap<Integer, BitSet>();
    	bitsetMap.put(bitSetOneIdentifier, new BitSet(n));
    	bitsetMap.put(bitSetTwoIdentifier, new BitSet(n));
    	
    	for (int i = 0; i < m; i++) {
    		
    		String operation = in.next();
    		int indexOne = in.nextInt();
    		int indexTwo = in.nextInt();
    		    		
    		switch (operation) {
    		case "AND":
    			bitsetMap.get(indexOne).and(bitsetMap.get(indexTwo));
    			break;
    		case "OR":
    			bitsetMap.get(indexOne).or(bitsetMap.get(indexTwo));
    			break;
    		case "XOR":
    			bitsetMap.get(indexOne).xor(bitsetMap.get(indexTwo));
    			break;
    		case "FLIP":
    			bitsetMap.get(indexOne).flip(indexTwo);    			
    			break;
    		case "SET":
    			bitsetMap.get(indexOne).set(indexTwo);    			
    			break;
    		}
    		
            System.out.println(bitsetMap.get(bitSetOneIdentifier).cardinality() + " " + bitsetMap.get(bitSetTwoIdentifier).cardinality());
    	}
    	
    	in.close();
    }
}
