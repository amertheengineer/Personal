
/*
  Amer Abdelaziz
  U25449742
  Section 001
 */

//Importing the Scanner

import java.util.Scanner;

public class StringMethodsProject {

	public static void main(String[] args) {
		// Scanner's name is "ab"
		Scanner ab = new Scanner(System.in);
// 	prompting the user's input
		System.out.println("Enter a phrase!");

		String x = ab.nextLine();

		System.out.println("Enter another phrase!");
	String y = ab.nextLine();
// Calling the .length method for the string to determine how long the string is
	System.out.println("Your first phrase has " +x.length() + " characters!");
	
	System.out.println("Your second phrase has " +y.length() + " characters!" );

	// string z is the composite of x and y
	
String z = x + y;

System.out.println(z);

System.out.println("Your final string has " +z.length() + " characters!");


// Replacing the vowels (a,e,i,o,u) and the capitals with "*" 
z = z.replace("a" , "*");
z = z.replace("A", "*");

z = z.replace("e", "*");
z = z.replace("E", "*");

z = z.replace("i", "*");
z = z.replace("I", "*");

z = z.replace("o", "*");
z = z.replace("O", "*");

z = z.replace("u", "*");
z = z.replace("U", "*");

// printing them out after the vowels have been replaced
System.out.println(z);
// Using the .indexOf method to see how many characters before the first occurrence of "*"
int j = z.indexOf("*");

// Printing it out :)

System.out.println("The number of characters prior to the first vowel is " +j);


}
}
