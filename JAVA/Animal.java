/*
 * Amer Abdelaziz
 * U25449742
 * Creating a base class to create an animal object for the dog, cat, and bird classes 
 */

import java.util.Calendar;
// Declaring the variables
public class Animal {
private String kind_of_animal;
private String name;
private String owner_name;
private Calendar DOB;
// Creating the constructor that has the variables as parameters
	public Animal (String Kind_of_animal, String Name, String Owner_name, Calendar DOB)
	{
		this.kind_of_animal = Kind_of_animal;
		this.name = Name;
		this.owner_name = Owner_name;
		this.DOB = DOB;
		
	}
	
		// Return methods 
	public String kind_of_animal()
	
		{
			return this.kind_of_animal;
		
		
		}
	public String name()
	
		{
		
			return this.name;
		
		}
	public String owner_name()
	
		{
		
			return this.owner_name;
		
		}
	public Calendar Date_of_Birth()
	
		{
		
			return DOB;
		
		
		}
	
	public String toString (){
		
		return  "kind of animal : " +kind_of_animal + ", name : " + name + ", Owner's name : " 
		+owner_name+ ", Date of Birth : "
		+(DOB.get(Calendar.MONTH)+1) +"/"+ DOB.get(Calendar.DATE) +"/" +DOB.get(Calendar.YEAR)
		+"";
				
		
	}
	
	
}
