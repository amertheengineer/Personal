/*
 * Amer Abdelaziz
 * U25449742
 * Creating a program that tests the Car class
 */
import java.util.Scanner;



public class Car_Test {

	public static void main(String[] args) {
		
		Scanner ab = new Scanner(System.in);
		
		// Prompting the user for the make of the car and storing it in a public String
		
		System.out.println("What's the make?");
		String newmake = ab.nextLine();
		
		// Prompting the user for the model of the car and storing it in a public String
		
		System.out.println("What's the model?");
		String newmodel = ab.nextLine();
		
		// Prompting the user for the year of the car
		
		System.out.println("What's the year?");
		int newyear = ab.nextInt();
		
		// Declaring the new car object with the new public parameters called "car1"
		
		Car car1 = new Car(newmake, newmodel, newyear);
		
		
		// Printing what's in the toString method
		
		System.out.println(car1.toString());
		
		
		// Checking if car1 is antique by calling the method isAntique and printing results.
		if(car1.isAntique()){
			
			System.out.println("This car is an antique");
			
		}else{
			
			System.out.println("The car is not antique");
			
		}

	}

}