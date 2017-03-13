//
//  JavaVarargsSimpleAddition.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/03/2017.
//
//  https://www.hackerrank.com/challenges/java-reflection-attributes

package it.hackerrank.advanced;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Collections;

class Student {

	private String name;
	private String id;
	private String email;

	public String getName() {

		return name;
	}

	public void setId(String id) {

		this.id = id;
	}

	public void setEmail(String email) {

		this.email = email;
	}

	public void anothermethod() {
	}
}

public class JavaReflectionAttributes {

	public static void main(String[] args) {
		
		Class<?> studentClass = Student.class;
		Method[] methods = studentClass.getDeclaredMethods();
		ArrayList<String> methodList = new ArrayList<>();

		for (Method method : methods) {

			methodList.add(method.getName());
		}

		Collections.sort(methodList);

		for (String name : methodList) {

			System.out.println(name);
		}
	}
}
