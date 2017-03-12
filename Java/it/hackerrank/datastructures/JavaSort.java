//
//  JavaSort.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 11/03/2017.
//
//  https://www.hackerrank.com/challenges/java-sort

package it.hackerrank.datastructures;

import java.util.*;

class StudentComparator implements Comparator<Student> {

	public int compare(Student studentOne, Student studentTwo) {
		
		if (studentOne.getCgpa() < studentTwo.getCgpa()) {
			
			return 1;
		} else {
			
			if (studentOne.getCgpa() == studentTwo.getCgpa()) {
				
				int nameOrder = studentOne.getFname().compareTo(studentTwo.getFname());
				
				if (nameOrder != 0) {
					
					return nameOrder;
				}
				
				return studentOne.getId() > studentTwo.getId() ? 1 : -1;
			}
			
			return-1;
		}
	}
}

class Student {

	private int id;
	private String fname;
	private double cgpa;

	public Student(int id, String fname, double cgpa) {

		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}

	public int getId() {

		return id;
	}

	public String getFname() {

		return fname;
	}

	public double getCgpa() {

		return cgpa;
	}
}

class JavaSort {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		List<Student> studentList = new ArrayList<Student>();
		
		while (testCases > 0) {
			
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();
			Student st = new Student(id, fname, cgpa);
			studentList.add(st);
			testCases--;
		}
		
		in.close();
		
		studentList.sort(new StudentComparator());

		for (Student st : studentList) {
			
			System.out.println(st.getFname());
		}
	}
}
