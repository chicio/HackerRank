//
//  JavaDateAndTime.java
//  HackerRank
//
//  Created by Fabrizio Duroni on 19/11/2016.
//
//  https://www.hackerrank.com/challenges/java-date-and-time

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class JavaDateAndTime {

	public static void main(String[] args) throws ParseException {

        Scanner in = new Scanner(System.in);
        String month = in.next();
        String day = in.next();
        String year = in.next();
        in.close();
        
        String inputDateStr = String.format("%s/%s/%s", day, month, year);
        Date inputDate = new SimpleDateFormat("dd/MM/yyyy").parse(inputDateStr);

        Calendar cal = Calendar.getInstance();
        cal.setTime(inputDate);
        String dayOfWeek = cal.getDisplayName(Calendar.DAY_OF_WEEK, Calendar.LONG, Locale.US).toUpperCase();
        
        System.out.println(dayOfWeek);
	}
}
