
/*
Amer Abdelaziz
U25449742
Writing a program that takes the input from the user (x1,y1) & (x2,y2)
and computes the distance
*/
// importing the Scanner and the DecimalFormat

import java.text.DecimalFormat;
import java.util.Scanner;

public class Distance {

	public static void main(String[] args) {
	Scanner ab = new Scanner(System.in);
	// declaring the variables
	double x1, x2 , y1 , y2 , deltax , deltay, d;
	// Asking the user to input the x and y
	
	System.out.println("Welcome to the distance calculator! Please input your x1 :");
	x1 = ab.nextDouble();
	System.out.println("Insert your y1 : ");
	y1 = ab.nextDouble();
	
	System.out.println("Insert you x2 : ");
	x2 = ab.nextDouble();
	System.out.println("Enter your y2 : ");
	y2 = ab.nextDouble();
	
	// The change in x and y squared using the math class
	
	deltax = Math.pow((x2 - x1), 2);
	deltay = Math.pow((y2-y1), 2);
	d = Math.sqrt((deltax + deltay));
	
	// Using the DecimalFormat class to have only 3 sig figs after the decimal  
	DecimalFormat ac = new DecimalFormat("0.###");
	
	// Printing out the distance !! Using the ac.format method .. 
	System.out.println("The distance is " +ac.format(d));
	
	
	
	
	}

}
