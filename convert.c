/*
    Amer Abdelaziz
    U25449742

        This program prompts the user to select
        a conversion option and convert the input
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Prompting the user...

    printf("Select an option for conversion: \n");
    printf("1 - Miles to Kilometers \n2 - Kilometers to Miles\n3 - Inches to Centimeters\n4 - Centimeters to Inches\n");
    int input;

    scanf("%d",&input);
    float miles , kilometers , inches ,centimeters ;
    /*
        In accordance to the project guidelines, we have the
        first two options as the miles to kilometers and the last two as
        the centimeters to inches and vice versa

        Using the switch statement and case numbers

    */
    switch(input)
    {
        case 1: printf("Miles to Kilometers! \n");
        printf("Enter miles to be converted : \n");
        scanf("%f", &miles);
        float kilo = miles*1.6093;
        printf(" Kilometers : %.4f",kilo);
        break;

        case 2: printf("Kilometers to Miles! \n");
        printf("Enter Kilometers to be converted : \n");
        scanf("%f", &kilometers);
        float  mil= kilometers * 0.6214;
        printf(" Miles : %.4f",mil );
        break;

        case 3: printf("Inches to Centimeters! \n");
        printf("Enter inches to be converted : \n");
        scanf("%f", &inches);
        float cent =  inches*2.54;
        printf("Centimeters : %.4f",cent);
        break;

        case 4: printf("Centimeters to Inches ! \n");
        printf("Enter Centimeters to be converted : \n");
        scanf("%f", &centimeters);
        float inc = centimeters * 0.3937;
        printf("Inches : %.4f", inc);
        break;

        default : printf("Error! Enter a number between 1 and 4");
        break;

    }
    return 0;
}
