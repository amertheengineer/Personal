/*
 * Amer Abdelaziz
 * U25449742
 * Attaining a csv file and printing them out, good dogs with three 
 * arrays (name, breed, and age).
 * Also changing the file name and adding 1 to the age of the dog.
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class Dog_Tester {

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
		
		
		Dogs[] Dogtest = new Dogs[100];
		
		
		try
					
		
			{
			
					// Nothing new here, just scanning the file
					
		            File file = new File(Filename);
		            
		            Scanner fileScanner = new Scanner(file);
		            // Replacing the file name with 2.csv instead of .csv
		            
		            String outfilename = Filename.replace(".csv", "2.csv");
		            
		            // Writing to the file..
		            FileOutputStream jeff = new FileOutputStream(outfilename, false);
					
					
					// Declaring the printwriter, which allows us to edit the file
					
					PrintWriter pw = new PrintWriter(jeff);
		      
		           
		            // Scanning the file till the it reaches an empty line
		           
		           while(fileScanner.hasNext())
		           		
		           			{
		            	
			        	   		// creating a new dog object called Dog1
		        	   			// That takes String a a it's parameter.
			        	   		
			            		String a = fileScanner.nextLine();
			            		Dogs Dog1 = new Dogs(a);
			            		// Splitting the string at every data type. Or comma
		            		 System.out.println(Dog1);
		            		 String [] dogdata = a.split(",");
		            		 // Converting the dogdata array to an integer
		            		 int newage = Integer.parseInt(dogdata[2]);
		            		 
		            		 pw.println(dogdata[0] + "," +dogdata[1] + "," +(newage+1));
		            		
            		
		           			}
           				
		           				pw.close();
           
		           				ok = true;
		          
					
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
