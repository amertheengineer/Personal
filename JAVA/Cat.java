/*
 * Amer Abdelaziz
 * U25449742
 * Creating a class that extends to the animal class and 
 * declares that cat is an animal
 */

import java.util.Calendar;

public class Cat extends Animals{
private String Breed;
private String preferred_catfood;
	public Cat(String name, String owner_name, Calendar DOB, String Breed, String 
			preferred_catfood)
	{
		
		// Using the super class method to invoke the constructor 
		super("Cat" , owner_name, name, DOB);
		
		this.Breed = Breed;
		this.preferred_catfood = preferred_catfood;
		
		
	}
	// Creating a toString class that returns the data from the super class , breed and catffood
		public String toString()
		{
			
			return super.toString() + ", Breed : " +Breed + 
					", Preffered Catfood : " +preferred_catfood ;
			
		}
			// Returning the breed and catfood separately
		public String Breed ()
		{
			
			return "Breed : " +Breed;
			
		}
		public String Preffered_Catfood()
		{
			
			return "Preffered Catfood : " + preferred_catfood;
		
		}
		

}
