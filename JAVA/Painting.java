import java.util.Scanner;

public class Painting {

	public static void main(String[] args) {
		// Scanner's name "xx"
		Scanner xx = new Scanner(System.in);
		// Declaring the squarefootage for the paint per gallon
		
		final int Coverage = 350;
		
		// declaring l w h
		int length , width , height;
		// declaring variables
		double surfacearea , paintneeded , afterpaintneeded;
		System.out.println("What's the length? ");
		// Getting user's input for l w h
		length = xx.nextInt();
		System.out.println("What's the width?");
		width = xx.nextInt();
		System.out.println("What's the height?");
		height = xx.nextInt();
		// Squarefootage area
		surfacearea = (2*length*width) + (2*length * height) + (2*width * height);
	
		// Total gallons ==> paintneeded, dividing the surface area by 350 (coverage) 
		
		paintneeded = surfacearea / Coverage;
		System.out.println("You'll need " + paintneeded + " gallons to paint");
		// getting the user's input for how many doors and windows there are...
		int doors , windows;
		System.out.println("How many doors?");
		doors = xx.nextInt();
		System.out.println("How many windows?");
		windows = xx.nextInt();
		// Assuming each door is 20 square feet and window is 15 square feet
		afterpaintneeded = (surfacearea - ((20*doors)+(15*windows)))/350;
		
		System.out.println("After the doors and windows, you'll need " +afterpaintneeded + " to finish the house");

	}

}
