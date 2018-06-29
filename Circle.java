// Amer Abdelaziz U25449742
public class Circle {

	public static void main(String[] args) {
	// Initializing the variable "radius" 
			int radius = 15;
			
// The double "PI" has a final value of 3.14, which means it is the only value PI can have //
			
		final double PI = 3.14159;
		// declaring the double "area"
		double area1 , area2;
		// declaring the area of the "Circle"
		
		area1 = PI * Math.pow(radius, 2);
		// printing out the "area"
		System.out.println("The area of the circle with radius " +radius + " is " +area1);
		// declaring the circumference
		double circumference1 , circumference2;
		// area of the circumference
		circumference1 = 2 * PI * radius;
		System.out.println("The circumference with radius " +radius + " is " +circumference1);
		
		
		// declaring another variable with radius of 25
		
		radius = 25;
		// Declaring the formula for the area
		area2 = PI * Math.pow(radius, 2);
		// Printing it out
		System.out.println("The area of the circle with radius " +radius + " is " +area2);
		 
		circumference2 = 2 * PI * radius;
		 System.out.println("The circumference with the radius " +radius + " is " +circumference2);
		// Calculating the ratio of the two circles. (Area change)
	double areafactor = area2 / area1;
	System.out.println("The change in area is " +areafactor);
		

	}

}
