//
//  CanYouAccess.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 13/03/2017.
//
//  https://www.hackerrank.com/challenges/can-you-access

package it.hackerrank.advanced;

import java.io.*;
import java.lang.reflect.*;
import java.util.*;
import java.util.regex.*;
import java.security.*;

public class CanYouAccess {

	public static void main(String[] args) throws Exception {
		DoNotTerminate.forbidExit();

		try {

			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int num = Integer.parseInt(br.readLine().trim());
			Object o;// Must be used to hold the reference of the instance of
						// the class Solution.Inner.Private

			OuterClass outerObject = new OuterClass();
			Class<?> innerClass = OuterClass.class.getDeclaredClasses()[0];
			Constructor<?> constructor = innerClass.getDeclaredConstructors()[0];
			constructor.setAccessible(true);
			o = constructor.newInstance(outerObject);

			System.out.println("An instance of class: " + o.getClass().getCanonicalName() + " has been created");
		} catch (DoNotTerminate.ExitTrappedException e) {
			System.out.println("Unsuccessful Termination!!");
		}
	}

	static class Inner {

		private class Private {

			private String powerof2(int num) {

				return ((num & num - 1) == 0) ? "power of 2" : "not a power of 2";
			}
		}
	}
}

class DoNotTerminate { // This class prevents exit(0)

	public static class ExitTrappedException extends SecurityException {

		private static final long serialVersionUID = 1L;
	}

	public static void forbidExit() {
		final SecurityManager securityManager = new SecurityManager() {
			@Override
			public void checkPermission(Permission permission) {
				if (permission.getName().contains("exitVM")) {
					throw new ExitTrappedException();
				}
			}
		};
		System.setSecurityManager(securityManager);
	}
}