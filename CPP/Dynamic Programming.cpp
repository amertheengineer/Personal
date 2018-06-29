#include <iostream>
#include <fstream>

using namespace std;

long long int candy_algorithm(int n, int s, int l); 


int main()
{
	int p, sample_size, square_candy, long_candy; // initializing variables
	long long int candy_combination;

	ifstream file_in;	// initializing input and output files
	ofstream file_out;
	
	file_in.open("input.txt");	// open file input.txt for reading
	
	if (!file_in.is_open())
	{
		cerr << "Error opening file for reading"; // prints error message if file is unable to be opened
	}
	
	file_out.open("output.txt"); 
	
	if (!file_out.is_open())
	{
		cerr << "Error opening file for writing"; // open file output.txt for writing
	}
	
	file_in >> p; // assigns the first value in the file which is the number of lines in the file for reading
	
	for (int i = 0; i < p; i++) // for loop that iterates to the end of the document which are the number of lines
	{
		file_in >> sample_size; // accepts the 3 parameters in each line of the file which is the sample size,
		file_in >> square_candy; // number of square candies and
		file_in >> long_candy;  // number of long candies
		
		candy_combination = candy_algorithm(sample_size, square_candy, long_candy); // applies our candy algorithm and stores it in the
		// candy combination variable
		file_out << candy_combination << endl;	// outputs the value and stores it into the output.txt file
	}

	file_in.close();	// closes input file
	file_out.close();	// closes output file
	return 0;
}


long long int candy_algorithm(int n, int s, int l)
{
	long long int candy_array[n]; // initializing array which is the size of the sample size
	
	candy_array[0] = 1; //first array slot holds value 1
	candy_array[1] = s;	// second array slot holds value s which is amount of squares
			
	for (int i = 2; i <= n; i++) // for loop that iterates through to the sample size
	{
		candy_array[i] = s * candy_array[i-1] + l * candy_array[i-2]; // iterative algorithm used to find the total combination  
	}
	
	return candy_array[n]; // returns value in the last slot of the array which contains all the combinations possible

}

