/*
 * Amer Abdelaziz
 * U25449742
 * Writing a program that determines whether a car is an antique or not 
 * and displays the year, model and make.
 */
public class Car {
	
	// Declaring the variables as private.
	
	private String make , model;
	private int year;
	
	// Declaring the constructor with private variables
	
	public Car() {
		
		make = "";
		model = "";
		year = 0;
		
	}
	// Declaring the constructor for public variables
	
	public Car (String newmake, String newmodel, int newyear) {
		
		make = newmake;
		model = newmodel;
		year = newyear;
		
	}
	// Creating a method that returns the make
	
	public String makename() {
		
		return make;
		
	}
	// Creating a method that returns the model
	
	public String Modelname(){
		
		return model;
		
	}
	// Creating a method that either returns true for antique and false for not antique
	
	public boolean isAntique(){
		
		if(year < 1991){
			
			return true;
			
		}
		
		return false;
	
	}
	// Creating a toString method that returns the year, make, and model
	public String toString(){
		
		
		return year + " " +make + " " +model;
		
		
	}
}
