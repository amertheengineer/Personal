/*
 * Amer Abdelaziz
 * U25449742
 * Creating a derived class from the Animals class
 * Considers the Dog to be an animal
 * Using the extends method for the animals class
 */

import java.util.Calendar;

public class Dog extends Animals{
private String breed;
private String favorite_treat;

	public Dog(String name, String owner_name, Calendar DOB
			,String breed,String favorite_treat) 
	{
		// Using the super class for getting the same info form the animals class
		super("Dog",name,owner_name,DOB);
		this.breed = breed;
		this.favorite_treat = favorite_treat;
	
		
	}
	// Return method
		public String toString()
		{
					
						return super.toString() +", Breed : " +breed +", "
								+ "Favorite treat : " +favorite_treat; 
					
		}
		public String Breed()
		{
					
						return "Breed : " +breed;
					
		}
		public String Favorite_treat()
		{
					
						return  "Favorite Treat : " +favorite_treat;
						
		}
		

}
