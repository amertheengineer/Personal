/*
 * Amer Abdelaziz 
 * U25449742
 * This program attains 10 user inputs and prints out the maximum, minimum, and the average.
 */

import java.text.DecimalFormat;
import java.util.Scanner;

public class Extremes {

	public static void main(String[] args) {
		// Naming the scanner "ab"
		Scanner ab = new Scanner(System.in);
	
	System.out.println("Enter integer!");
	// Declaring all the integers and doubles
	int a1 = ab.nextInt() , Maximum = a1 , Minimum = a1 , i, count = 0;
	double average, sum =0;
	// Applying the condition if user inputs 0 for the first number
	if(a1 == 0)
		{
			System.out.println("Error!");
		}
		// Start of the else statement
		else{
		/* Declaring that the sum is equal to 1 initially if the user doesn't input 1 and
		 the count as well 	
		 */
	sum = a1;
	count = 1;
	
	

	
	/* The for loop is running 9 times (total 10) plus the 1 from earlier
	 * Within the for loop, it runs the if another input = 0, then it stops there
	 * And declares the results of max min and average
	 * Else if the an input is more than a1 = max (First input) then replace it with the 
	 * maximum, similarly with the minimum	 
	 * For the count, we increase it by 1 9 times til user inputs 0 or reaches 9
	 * 
	 */
	for( i = 0; i < 9; i++)
						 {
		
		
		System.out.println("Enter integer!");
		a1 = ab.nextInt();
		if(a1 == 0)
		{
			
		
		break;	
			
		}
		else
			{
		if(a1 > Maximum)
		{
				Maximum = a1 ;
				
		
		}
		else if(a1 < Minimum){
				Minimum = a1;		
							 }
			sum = sum + a1 ;
			count++;
			
			}
		// End of for loop
							}
		// Printing out the max, min, sum, and average
	
	System.out.println("Maximum is " +Maximum);
		System.out.println("Minimum is " +Minimum);
		
		System.out.println("The sum is " +sum);
	average = (sum) / count;
	
		DecimalFormat ff = new DecimalFormat("0.###");
		
		
	System.out.println("The average is " +ff.format(average));
		// End of the first else statement
		}
	}

}

