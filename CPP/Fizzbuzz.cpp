/*
Amer Abdelaziz
U25449742

This program prints either FizzBuzz, FizzWoof,
BuzzWoof, Fizz, Buzz, and Woof For multiples of 3 and 5,
For multiples of 3 and 7,
For multiples of 5 and 7, mutiples of 3,
multiples of 5, multiples of 7 respectively.
*/

#include <iostream> 
#include <cstdlib>
using namespace std;
int main() {
	static int  i;
	for (i = 1; i <= 100; i++) {
		if (((i % 3) == 0) && (i % 5) == 0)
			std::cout << "FizzBuzz" << endl;
		else if (((i % 3) == 0) && (i % 7) == 0)
			std::cout << "FizzWoof" << endl;
		else if (((i % 5) == 0) && (i % 7) == 0)
			std::cout << "BuzzWoof\n" << endl;
		else if ((i % 3) == 0)
			std::cout << "Fizz " << endl;
		else if ((i % 5) == 0)
			std::cout << "Buzz" << endl;
		else if ((i % 7) == 0)
			std::cout << "Woof " << endl;

		else std::cout << i << std::endl;



		system("PAUSE");
	} return 0;
}
