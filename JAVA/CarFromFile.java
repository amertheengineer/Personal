/*
 *Amer Abdelaziz
 *U25449742
 *Project is the same as the solution on the COP 2510 website 
 *Only revision is a new constructor 
 */

import java.util.Scanner;

public class CarFromFile
{
	Scanner ab = new Scanner(System.in);
	
    // Instance variables
    private String make;
    private String model;
    private int year;	
    
    //-----------------------------------------------------
    // Constructor - sets up a car object by initializing 
    // the make, model, and year of the car.
    //-----------------------------------------------------
    public CarFromFile(String make_, String model_, int year_)
    {
        make = make_;
        model = model_;
        year = year_;
    }
    // New constructor
    public CarFromFile(Scanner ab)
    {
    	
    	make = ab.nextLine();
    	model = ab.nextLine();
    	year = ab.nextInt();
    	ab.nextLine();
   
    
    }
            
    //------------------------------------------------------
    // Method isAntique returns true if the car is more than 
    // 25 years old.
    //-------------------------------------------------------
    public boolean isAntique()
    {
        return (2016 - year) > 25;
    }
            
    //------------------------------------------------------
    // Returns a string representation of a car.
    //------------------------------------------------------
    public String toString()
    {
        String result = year + " " + make + " " +  model;
        return result;
    }
}



