/*
  Amer Abdelaziz
  U25449742
  Creating a program that takes the number of arrays a user inputs and
  allows them to input them and print them out in reverse and normal order.
  
 */

import java.util.Scanner;

public class Arrayclass {

	public static void main(String[] args) {
		int u;
		
		
		Scanner ab = new Scanner(System.in);
		// Prompting the user for how many arrays they have
		System.out.println("How many arrays you have ?");
		u = ab.nextInt();
		
		String[] input = new String[u];
		
		// Asking the user to input the array1-number of arrays user inputs
			for(int x = 0 ; x < input.length; x++)
			{
			int z = x+1;
			System.out.println("Enter Array " +z);
			
			
			input[x] = ab.next();
			
			
			
			}
		System.out.println("The array contains :" );
		// Printing the arrays the user inputs.
		
		for(int x = 0 ; x < input.length; x++)
		{
			System.out.println(input[x]);
		}
			System.out.println("The arrays in reverse are : ");
			// Reversing the arrays , starting from the length of the array till zero and x 
			// decrements
			for(int x = input.length -1; x >= 0; x--)
			{
				
				System.out.println(input[x]);
			}
											}

					}
