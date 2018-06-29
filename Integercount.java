	/*
	  Amer Abdelaziz
	  U25449742
	  Writing a program that counts the count of numbers a user inputs
	  
	 */


import java.util.Scanner;

public class Integercount {

	public static void main(String[] args) {
		
		Scanner ab = new Scanner(System.in);
		
		
		int k, count = 0;
	
				// Declaring an array that sets all the counts of variables to 0 initially
		int [] counts = new int[51];
				
				// Start of the do while loop
				do
				 {
					// Prints out and prompts the user for the input
				System.out.println("Next input ");
				k = ab.nextInt();
					/*
					  Applying the condition that the input has to be less than 50 
					  and greater than 0
					 */
					if(k > 50 || k < 0 )
						{
				System.out.println("Error");
				
						}
					// Otherwise , increment the count till user inputs 0
						else
						{	
				
							counts[k]++;
				
						}
				   }while(k != 0);
			
			System.out.println("value" + "\t" + "Count");
			/*
			 Doing a for loop up to 50 (Supposed to print out the numbers up to 50,
			 only if count > 0. 
			 */
		for(int d = 1; d < 50 ; d++)
			{
				if(counts[d] > 0)
				{
				
				System.out.println(d + " : " + "\t" +counts[d]);
				
				}
				
			}
			
			System.out.println("End");
		
			}
			
	
		
	}


