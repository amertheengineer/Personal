/*
Amer Abdelaziz
U25449742

This code prompts the user ot enter the total number of times a coin
is flipped to produce heads or talis
when a coin
*/


#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{

	int value;

	cout << "Enter the number of times you want to toss the coin: \n" << endl;
	cin >> value;

	if (value < 10)
	{
		cout << "The number of tosses must be greater than 10. Re-enter:" << endl;
		cin >> value;
	}
	else
	{
		int temp = 0;
		int count1 = 0, count2 = 0;
		for (int i = 1; i <= value; i++)
		{
			/* Producing heads or tails randomly*/
			temp = rand() % 2;
			/*  Checking whether the temp value is 0 or 1
			to determine heads or tails respectively  */
			if (temp == 0)
			{

				cout << "Heads " << endl;
				count1++;

			}
			if (temp == 1)
			{

				cout << "Tails " << endl;
				count2++;
			}



		}
		double sum = double(count1 + count2);
		cout << "Heads count : \n" << count1 << endl;
		cout << "Tails count : \n" << count2 << endl;

		if ((double)(count1 / sum) > 0.45 && (double)(count1 / sum) < 0.55)
		{
			cout << "This simulation was realistic";
		}
		else
		{
			cout << "This simulation was not realistic";
		}
	}
	system("Pause");


}
