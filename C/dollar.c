
/*
 Amer Abdelaziz
 U25449742

    This program takes a dollar amount from

    the user and prints out to the user the least

    number of bills they need.

    The max the user can input is $1000000000


*/





#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Ask user for input!
    printf("Enter a dollar amount :");

    int input;


    scanf("%d",&input);

    // Check if input is more or less than the limit

    if(input > 1000000000||input<0)
        {


                printf("Invalid amount! '%d' \n", input);
                    printf("Amount must be between 0 and 1000000000");

        }
            else
                {
 int dollars;

            /* Doing the math ==> taking the input and dividing it by 20

                Then subtracting the result

            */

        printf("Bills : \n");

                // $20s

            dollars = input / 20;

            printf("$20s : %d \n", dollars);

            input = input - (dollars * 20);

                    // $10s

                dollars = input / 10;

                printf("$10s : %d \n", dollars);

                input = input - (dollars *10);

                        // $5s
                    dollars = input / 5;

                    printf("$5s : %d \n", dollars);

                    input = input - (dollars * 5);

                            // $1s

                        dollars = input / 1;

                        printf("$1s : %d \n", dollars);







                }

    return 0;
}
