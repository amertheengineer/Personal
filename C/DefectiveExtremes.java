	


/*
 * Amer Abdelaziz
 * U25449742
 * Fixing a defective program that doesn't stop at the count of 10 but only for 0
 * Any fixes has my name next to it.
 * 
 */
import java.util.Scanner;
		import java.text.DecimalFormat;
public class DefectiveExtremes {

	public static void main(String[] args) {
	

	
		        Scanner scanner = new Scanner(System.in);
		        int n, count = 0, min = 0, max = 0, total = 0;
		       
		        System.out.println("Enter up to ten integers.");
		        System.out.println("To stop before ten, enter a zero.");
		        do
		        {
		            System.out.print("Next input: ");
		            n = scanner.nextInt();
		            if (n != 0)
		            {
		                if (count == 0)
		                {
		                    // This is the first input.  Initialize min and max.
		                    min = n;
		                    max = n;
		                }
		                else
		                {
		                    // Additional input.  Update min and max
		                    if (n < min)
		                    {
		                        min = n;
		                    }
		                    if (n > max)
		                    {
		                        max = n;
		                    }
		                }
		                total += n;
		                count++;
		            } 
		        }
		        // Making the program stop at count < 10 ==> Amer comment
		        while (n != 0 && count < 10);
		       
		        
		       
		        if (count > 0)
		        {
		        	
		        		
		        	
		            // Output extremes and average
		            System.out.println("The minimum is " + min);
		            System.out.println("The maximum is " + max);
		            
		            DecimalFormat decimalFormatter = new DecimalFormat("0.####");
		            double average = (double)total / count;
		            System.out.println("The average is " + decimalFormatter.format(average));
		        
		        	}
		        else
		        {
		            System.out.println("No inputs were entered");  
		        }
		    
		
	}
	}


