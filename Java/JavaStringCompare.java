
import java.util.Scanner;

public class JavaStringCompare {

    public static void main(String[] args) {
    	
    	Scanner sc = new Scanner(System.in);
    	String input = sc.nextLine();
    	int stringLength = sc.nextInt();
    	sc.close();
    	
    	String minString = null;
    	String maxString = null;
    	String currentSubstring = "";
    	
    	for (int i = 0; i <= input.length() - stringLength; i++) {
    		
    		currentSubstring =  input.substring(i, i + stringLength);
    		
    		if (minString == null || currentSubstring.compareTo(minString) <= 0) {
    			
    			minString = currentSubstring; 
    		}
    		
    		if (maxString == null || currentSubstring.compareTo(maxString) > 0) {
    			
    			maxString = currentSubstring; 
    		}
    	}
    	
    	System.out.println(minString);
    	System.out.println(maxString);
    }
}
