//
//  JavaIterator.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-iterator

package it.hackerrank.objectorientedprogramming;

import java.util.*;

public class JavaIterator {
   
   static Iterator<Object> func(ArrayList<Object> mylist) {
	   
      Iterator<Object> it = mylist.iterator();
      
      while (it.hasNext()) {
    	  
         Object element = it.next();
        		 
         if (element instanceof String && !element.equals("###")) {
        	 
            break;
         }
      }
      
      return it;
   }
   
   @SuppressWarnings({"unchecked"})
   public static void main(String []args) {
	   
      ArrayList<Object> mylist = new ArrayList<Object>();
      
      Scanner sc = new Scanner(System.in);
      int n = sc.nextInt();
      int m = sc.nextInt();
      sc.close();
      
      for (int i = 0;i<n;i++) {
    	  
         mylist.add(sc.nextInt());
      }
      
      mylist.add("###");
      
      for (int i = 0; i < m; i++) {
    	  
         mylist.add(sc.next());
      }
      
      Iterator<Object> it = func(mylist);
      
      while (it.hasNext()) {
    	  
         Object element = it.next();
         System.out.println((String)element);
      }
   }
}
