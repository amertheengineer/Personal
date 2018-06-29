/*
 * Amer Abdelaziz
 * U25449742
 * Creating a class that is derived from the Animals class
 * Using the extends Animals addition allows us to ensure that Bird
 * is an animal
 */

import java.util.Calendar;
public class Bird extends Animals{
private String species;
private double wingspan;
// Declaring string variables
// Using the super class method that says that we have bird, name, owner name, and DOB
	public Bird( String Name, String Owner_name, Calendar DOB, 
			String species, double wingspan) {
		super("Bird", Name, Owner_name, DOB);
		this.species = species;
		this.wingspan = wingspan;
		
		
	}
	// Returning the information
	public String toString()
	{
		
		return super.toString() + ", Species : " +species + ", Wingspan : " +wingspan;
		
	}
	public String Species ()
	{
		
		return "Species : " +species;
		
	}
	public double Wingspan()
	{
		
		return wingspan;
	
	}
	

}
