/*
  Amer Abdelaziz
  U25449742
 Creating a program that takes the user input and prints out the number of spaces
 As Es Ss and Ts (Upper and lower cases)
   */
// Importing Scanner and calling it "ab"
import java.util.Scanner;

public class Count2 {

	public static void main(String[] args) {
		
		Scanner ab = new Scanner(System.in);
		System.out.println("Enter a string or phrase : ");
		// declaring strings and variables
		String str = ab.nextLine();
		int length , spacecount = 0 , countA = 0 , countE = 0 , countS = 0 , countT = 0, count = 0;
		
		length = str.length();
		// Calling a new character "c"
		char c = ' ';
		
		int k = 0;
		
		// Running the for loop for as long as the string's length
		for(int x = 0 ; x < length ; x++){
			/*
			 	The switch case checks if the string has 'a , e , s , t and a space'
			 	Also we increment the count for each letter
			 	
			 */
			
			
			
			switch (k){
			// case'a or A'
			case 'a' : 
			case 'A' : countA++;
			break;
			
			// case 'e or E'
			case 'e' :
			case 'E' :countE++;
			break;
			
			// case 's or S'
			case 's' :
			case 'S' : countS++;
			break;
			
			// case ' t or T'
			case 't' :
			case 'T' :countT++;
			break;
			
			// case ' '
			case ' ' : spacecount++;
			break;
			default:
			break;
			
				
			
			}
			// Scanning for all the characters in the string.
			k = str.charAt(x);
			
			
		
		
			
		}
			// Printing it out..
		
			System.out.println("There are " +spacecount + " spaces in the sentence!");
			System.out.println("There are " +countA + " As");
			System.out.println("There are " +countE + " Es");
			System.out.println("There are " +countS + " Ss");
			System.out.println("There are " +countT + " Ts");
		
	
		
	}

}
