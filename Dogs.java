/*
 * Amer Abdelaziz
 * U25449742
 * Creating a class that stores the data from a file of dogs (name, breed, and age)
 */

import java.util.Scanner;

public class Dogs {
	
	Scanner ab = new Scanner(System.in);
	
	private String name;
	private String breed;
	private int age;
	private boolean isValid;
	
	// Creating a constructor with the string "dogname" as its parameter.
	/*
	 * Applying the condition to see if the length of the array is not equal to 3
	 if it it's not, then the dog names will be labeled as "Good dogs", if it is, then 
	 label it as  a "bad dog"
	 */
	public Dogs(String dogname)
    {
		
		// Splitting the string at every comment and storing it into an array
		
		String [] dog_data = dogname.split(",");
		
		if(dog_data.length != 3)
		
			{
			
				isValid = false;
			
			}else
				{
				
				/*
				 * The this.name will be the first aray (at position 0)of dog_data and 
				 * so on with the breed and age.  
				 * 
				 */
				isValid = true;
				
					this.name = dog_data[0];
					this.breed = dog_data[1];
					this.age = Integer.parseInt(dog_data[2]);
					
					
				}
			
			
			
    }
	
		// Reading the file and calling the scanner ab (the scanner that reads the file)
	public Dogs (Scanner ab){
		
		this.name = ab.nextLine();
		this.breed = ab.nextLine();
		this.age = ab.nextInt();
		ab.nextLine();
		
		
	}
	
		// Returning the name, breed, and age
	public String toString(){
		if(isValid)
		{
			return
				this.name + " " +
				this.breed +" " +
				this.age + "\n";
			
			
		}else
			{
			
			return "Dog not valid";
			
			}
		
		
	}

}
