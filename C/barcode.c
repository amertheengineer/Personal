/*
    Amer Abdelaziz
    U25449742

        This program takes in a binary input and finds the edges of light
        and dark regions
        It also processes an 8 bit and does an algorithm to the 1s and 0s based on
        order

*/

#include <stdio.h>
#include <stdlib.h>
void edge(int n, int a1[], int a2[]);
int main()
{
    // Prompting the user
    printf("Enter bar code :(1s and 0s)!\n");
    int barcode[8], output[8], i;
    for(i = 0; i < 8; i++)
    {
        scanf("%1d", &barcode[i]);
    }
    // Calling the function
       edge(8,barcode,output);
       printf("The output : \n");
       for(i = 0; i < 8; i++)
       {
           printf("%d \n", output[i]);
       }

    return 0;
}

void edge(int n, int a1[], int a2[])
{
    // Looping through the array and applying the algorithm

        int i = 0;
        int prev = a1[i];

        a2[i++] = 0;
        while(i < n)
        {
            if(prev == a1[i])
            {
                a2[i] = 0;
            }
                else{
                    a2[i] = 1;

                }
                    prev = a1[i];
                    i++;
            }

}
