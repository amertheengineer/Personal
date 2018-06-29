/*
    Amer Abdelaziz
    U25449742

    This program prompts the user to enter a three digit number and
    replaces each integer by the sum of that digit plus 6 modulus 10

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter a three digit number :\n");
    int input;

    scanf("%d",&input);

// Checking the condition

    if(input < 100 || input > 999)
    {
        printf("Error! The number must be between 100 and 999!");

    }
// If the number is valid

        else {
                    int ones, tens, hunds, newten;
// Performing the operations using the remainder

                    ones = input % 10;

                    tens = input % 100;
                    newten = (tens - ones)/10;

                    hunds = (input -tens) /100;

                    printf("Output : \t");
                    printf("%d", (hunds +=6)%10);
                    printf("%d", (newten+=6)%10);
                    printf("%d", (ones+=6)%10);
        }
    return 0;
}
