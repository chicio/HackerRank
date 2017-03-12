//
//  JavaPriorityQueue.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 12/03/2017.
//
//  https://www.hackerrank.com/challenges/java-priority-queue

package it.hackerrank.datastructures;

import java.util.*;

class TheStudent {
	
	private int token;
	private String fname;
	private double cgpa;

	public TheStudent(int id, String fname, double cgpa) {
		
		super();
		this.token = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}

	public int getToken() {
		
		return token;
	}

	public String getFname() {
		
		return fname;
	}

	public double getCgpa() {
		
		return cgpa;
	}
}

class StudentComparatorQueue implements Comparator<TheStudent> {

    public int compare(TheStudent p, TheStudent q) {
    	
    if (q.getCgpa() == p.getCgpa()) {
    	
        if(p.getFname().equals(q.getFname())) {
        	
            return q.getToken() < p.getToken() ? -1 : 1;
        }
        
        return p.getFname().compareTo(q.getFname());
    } 
    else {
    	
        return q.getCgpa() > p.getCgpa() ? 1 : -1;
    }
}
}

class JavaPriorityQueue {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int totalEvents = Integer.parseInt(in.nextLine());
		PriorityQueue<TheStudent> pq = new PriorityQueue<TheStudent>(new StudentComparatorQueue());

		while (totalEvents > 0) {

			String event = in.next();
			
			switch (event) {
			case "ENTER":
				String name = in.next();
				double cgpa = in.nextDouble();
				int token = in.nextInt();
				pq.add(new TheStudent(token, name, cgpa));
				break;
			case "SERVED":
				pq.poll();
				break;
			}

			totalEvents--;
		}
		
        if (pq.isEmpty()) {
        	
            System.out.println("EMPTY");
        } else {
        	
            while (!pq.isEmpty()) {
            	
                TheStudent s = pq.remove();
                System.out.println(s.getFname());
            }
        }	
        
		in.close();
	}
}
