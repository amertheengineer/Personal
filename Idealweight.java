// importing the scanner
import java.util.Scanner;

public class IdealWeight {

	public static void main(String[] args) {
		// Naming the scanner "ab"
		Scanner ab = new Scanner(System.in);
		// declaring all the parameters
		int heightinfeet = 0 , heightinches = 0;
		double maleheight = 106 , femaleheight , maleweight = 0 , femaleweight = 0 , fmaleweight = 0;
		double ffemaleweight = 0;
		
		// asking the user..
		System.out.println("Are you a male or female?");
		String x = "male or female";
		x = ab.next();
		// First condition==> if user is "male" then proceed with what's in brackets
		if(x.equals("male")){	
			{
				{
					
				// Question the user...
			System.out.println("how many feet?");
			// All the information from the powerpoint
		heightinfeet = ab.nextInt();
		// 106 + how many inches over 5 feet times 6
		}if(heightinfeet >= 5){
			maleweight = 106;
			
		}if(heightinfeet >= 6){
			maleweight = 106 + (12 * 6);
			
		}if(heightinfeet >= 7){

			maleweight = 106 + (24 * 6);
		}
		// question how many inches and multiply by 6 and add to feet.
		System.out.println("How many inches?");
		heightinches = ab.nextInt();
		// final male weight formula
		fmaleweight = maleweight + (6*heightinches);
		
		System.out.println("Your ideal weight is " +fmaleweight);
		
		}
		}
		// Same for female except for 5 times every inch higher than 5 foot. And start with 100 lbs
		if(x.equals("female")){	
			
			System.out.println("how many feet?");
			
		heightinfeet = ab.nextInt();
		}if(heightinfeet >= 5){
			femaleweight = 100;
			
		}if(heightinfeet >= 6){
			femaleweight = 100 + (12 * 5);
			
		}if(heightinfeet >= 7){

			maleweight = 100 + (24 * 5);
		}
		System.out.println("How many inches?");
		heightinches = ab.nextInt();
		ffemaleweight = femaleweight + (5*heightinches);
		
		
		System.out.println("Your ideal weight is " +ffemaleweight);
		
}
			
			
			
			

	

}

