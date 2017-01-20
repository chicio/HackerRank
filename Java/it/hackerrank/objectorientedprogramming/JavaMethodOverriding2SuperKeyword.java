//
//  JavaMethodOverriding2SuperKeyword.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-method-overriding-2-super-keyword

package it.hackerrank.objectorientedprogramming;

class BiCycle {
	
	String define_me() {
		
		return "a vehicle with pedals.";
	}
}

class MotorCycle extends BiCycle {
	
	String define_me() {
		
		return "a cycle with an engine.";
	}
	
	MotorCycle() {
		
		System.out.println("Hello I am a motorcycle, I am "+ define_me());
		String temp = super.define_me(); //Fix this line (THE CHALLENGE WAS TO ADD super...)
		System.out.println("My ancestor is a cycle who is "+ temp );
	}
}		
		
public class JavaMethodOverriding2SuperKeyword {

	public static void main(String []args) {
		 
		@SuppressWarnings("unused")
		MotorCycle M = new MotorCycle();
	}
}
