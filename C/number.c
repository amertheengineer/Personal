/*

    Amer Abdelaziz
    U25449742

    This program takes in an array of numbers
    using argv and argc as inputs

*/
#include <stdio.h>
#include <stdlib.h>
#define N 10
#include <string.h>

int main(int argc, char *numbers[])
{



   if(argc == 1)
   {
       printf("Enter a command line argument!");
   }
// Largest algorithm
    else
    {
        if(!strcmp(numbers[1], "-l"))
        {

        int max = atoi(numbers[2]);
        int i;
        for(i = 2; i <= N;i++)
        {
            if(max< atoi(numbers[i]))
            {
                max = atoi(numbers[i]);
            }
        }
            printf("The largest is : %d\n",max);

        }


// Smallest algorithm
          else
          {
              if(!strcmp(numbers[1], "-s"))
              {

                    int min = atoi(numbers[2]);
                    int i;
                    for(i = 2; i <= N;i++)
                    {
                        if(min > atoi(numbers[i]))
                        {
                            min = atoi(numbers[i]);
                        }
                    }
                    printf("The smallest is : %d\n",min);

        }

              }

          }
    return 0;
}


