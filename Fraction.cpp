/*
	Amer Abdelaziz
	U25449742

		This program adds two fraction objects
		using operator overloads including 
		+ - * / operations 

*/
/* Including the fraction header file */
#pragma once
#include "Fraction.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	fraction f1, f2;

	cout << "Enter the first fraction in the form a / b:";
	cin >> f1;

	cout << "Enter the second fraction in the form a / b:";
	cin >> f2;

	cout << "Fraction 1 = " << f1 << endl;
	cout << "Fraction 2 = " << f2 << endl;

	cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
	cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
	cout << f1 << " * " << f2 << " = " << (f1*f2) << endl;
	cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;


	return 0;



	system("PAUSE");

}







#pragma once

/* 
	This header file contains the class with accessor 
	and mutator functions along with other functions	

*/
#include <iostream>

#ifndef Fraction_h

#define Fraction_h

using namespace std;


class fraction
{
private:
	int numerator;
	int denominator;

public:
	/* Constructor with no parameters */
	fraction()
	{
		numerator = 0;
		denominator = 1;

	}
	/* Other constructor with two parameters */
		fraction(int num, int denum)
		{
			if (denominator == 0)
			{
				cout << "Error, can't have a 0 denominator ";
			}
			else
			{
				numerator = num;
				denominator = denum;
			}

		};
		/* Accessor functions */
		int getnumerator() const
		{
			return numerator;
		}
		int getdenominator() const
		{
			return denominator;
		}

		/* Mutator functions */
			void setnumerator(int num)
			{
				numerator = num;
			}

			void setdenominator(int den)
			{
				denominator = den;
			}
			/* Signs functions to negate the fraction if needed */
			void signs()
			{
				int numtemp = getnumerator();
				int dentemp = getdenominator();

				if (dentemp< 0)
				{
					numtemp *= -1;
					dentemp *= -1;
				}
				setnumerator(numtemp);
				setdenominator(dentemp);

			}
			/* Simplify function that simplifies the fraction */
					void simplify()
					{
						signs();

						int sign = 1;
						int num = getnumerator();
						int den = getdenominator();
						if (num < 0)
						{
							num *= -1;
							sign = -1;


						}
						for (int i = (num * den); i > 1; i--)
						{
							if ((num % i == 0) && (den % i == 0))
							{
								num /= i;
								den /= i;
							}
						}
						num *= sign;
						setnumerator(num);
						setdenominator(den);

					}

					/* Operator overloads declaration */

						friend ostream& operator<< (ostream&, const fraction&);
						friend istream& operator>> (istream&, fraction&);

						fraction operator + (fraction);
						fraction operator -  (fraction);
						fraction operator * (fraction);
						fraction operator / (fraction);

	};
#endif


#include <iostream>
#include "Fraction.h"
using namespace std;

/* From class */

ostream& operator <<  (ostream& os, const fraction& fraction1)
{    
				//note that we print out a / as it is simply easier to do so!    
				os << fraction1.numerator << " / " << fraction1.denominator;    
				return os;
}
istream& operator>> (istream& is, fraction& fraction2) 
{
	char ch;       
	is >> fraction2.numerator; 
	//get the numerator   
	is >> ch;                      
	//read and discard the '/'   
	is >> fraction2.denominator;  
	//get the denominator        
	return is;
}
/* Operator overloads code */
/* The + operator will add the two fractions */
fraction fraction ::operator + (const fraction right )
{
	
	int nsum = ((*this).getnumerator()*(right.getdenominator())+ (right.getnumerator())*((*this).getdenominator()));
	int dsum = (*this).getdenominator() * right.getdenominator();
	fraction result(nsum,dsum);
	return result;

}
fraction fraction ::operator - (const fraction right)
{
	int ndif = ((*this).getnumerator())*(right.getdenominator()) - (right.getnumerator())*((*this).getdenominator());
	int ddif = (*this).getdenominator() * right.getdenominator();
	fraction result(ndif, ddif);
	return result;
}
fraction fraction ::operator * (const fraction right)
{
	int nmul = ((*this).getnumerator()) * right.getnumerator();
	int dmul = (*this).getdenominator() * right.getdenominator();
	fraction result(nmul, dmul);
	return result;
}
fraction fraction ::operator / (const fraction right)
{
	int ndiv = ((*this).getnumerator()) * right.getdenominator();
	int ddiv = (*this).getdenominator() * right.getnumerator();
	fraction result(ndiv, ddiv);
	return result;
}


