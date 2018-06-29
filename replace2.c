/*
    Amer Abdelaziz
    U25449742

    This program prompts the user to enter the number of digits
    of a number and replaces the sum of that digit by sum
    of that digit plus 6 modulus 10

*/
#include <stdio.h>
#include <stdlib.h>

void replace(int *a, int *b, int n);
void swap(int *p, int *q);
int main()
{
    printf("Enter the number of digits of the number : \n");
    int digits;
    scanf("%1d", &digits);

    printf("Enter the number : \n");
    int  i, input[digits], output[digits];

    // Scanning using pointer arithmetic

    for(i = 0; i < digits; i++)
    scanf("%1d", (input + i));

    // Printing the output using pointer arithmetic

    printf("The output : \n");
    replace(&input,&output,digits);
    swap(&output[0],&output[digits-1]);
    for(i = 0; i < digits; i++)
    {

        printf("%d", *(output + i));

    }


    return 0;
}

// The replace function replaces each element of the array with 6 plus modulus 10

void replace(int *a, int *b, int n)
{

    int* p = &a[0];
    int* q = &b[0];

    for(p = a, q = b;  p < a+n, q < b + n; p++, q++)
    {
        *q = (*p+6)%10;
    }

}

// The swap function swaps two values

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;

}
