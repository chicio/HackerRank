//
//  JavaInheritanceI.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-inheritance-1

package it.hackerrank.objectorientedprogramming;

class Animal {
	
	void walk() {
		
		System.out.println("I am walking");
	}
}

class Bird extends Animal{
	
	void fly() {

		System.out.println("I am flying");
	}
	
	void sing() {
		
		System.out.println("I am singing");
	}
}

public class JavaInheritanceI {

	public static void main(String[] args) {

		  Bird bird = new Bird();
		  bird.walk();
		  bird.fly();
	      bird.sing();		
	}
}
