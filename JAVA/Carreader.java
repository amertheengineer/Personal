/*
 * Amer Abdelaziz
 * U25449742
 * Attaining a file name from the user and counting the number of cars in 
 * the file and identify them
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Carreader {

	public static void main(String[] args)
			throws FileNotFoundException
		 {
		// Declaring the boolean ok to false (If user inputs a file name not found)
		
		boolean ok = false;
		
		// Running the while loop as long as the file name is true or found
		
	while(!ok)
	{
			// Prompting the user for the file name and scanning the name of the file
		
		System.out.println("Enter file name : ");
		Scanner ac = new Scanner(System.in);
		String Filename = ac.nextLine();
		
		// Declaring the array to say that there can't be more than 100 cars. 
		
		CarFromFile [] savedcar = new CarFromFile[100];

		// Running the try command to test the file
		
		try
			{
			
			
			
            File file = new File(Filename);
            
            Scanner fileScanner = new Scanner(file);
            
            // Declaring the variables 
            
            int carcount = 0;
            ok = true;
            
            // Operating the while loop till the file reaches an empty line
            
           while(fileScanner.hasNext())
           	{
            		
	            	carcount++;
	            	
	            	// Creating a new car object called "Car1"
	            	CarFromFile Car1 = new CarFromFile(fileScanner);
	            	System.out.println(Car1);
	            	
	            	// Using the array savedcar to store Car1 into each slot of carcount 
	            	
	            	savedcar [carcount] = Car1;
            	
         
           	}
           
           	// Verifying that the array is working and printing out the cars in order
	           	for(int i = 1; i <= carcount;i++)
	           		{
	           		
	           			System.out.println("Car " +i +" is " +savedcar[i]);
	           	
	           		}
	           
        
            System.out.println(+carcount + " cars created");
            
            
			}
        		// Testing if the file name exists or not
		
				catch(FileNotFoundException ex)
				{
				
						System.out.println("File not found mate! ");
						System.out.println("Please try again !");
						
				}
	}
		 }

						}
