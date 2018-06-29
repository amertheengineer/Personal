/*

    Amer Abdelaziz
    U25449742

        This program prompts the user to enter an array of numbers
        and creates a union and intersection array using a method of
        counting the number of elements in the array ({0 1 0 1 1 0 1 1 0 0 1})


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Prompting the user

    int i, Na;
    printf("Enter numbers between 1 and 10! \n");
    printf("Enter the number of elements in the first set : \n");
    scanf("%d", &Na);
    printf("Enter the first set of numbers : \n");
    int a[Na], j = 0, an[10] = {0};

    for( i = 0; i < Na; i++)
    {
        scanf("%d", &a[i]);
    }

   // Keeping track of how often has a certain number occurs in the array

            printf("The first set : \n");

            for(j = 0; j < 10; j++)
            {
                for(i = 0; i < Na; i++)
                {
                    if(a[i] == j)
                    {
                        an[j]++;
                    }
                }


                printf("%d %d \n", j , an[j]);
            }


            // Prompting the user to enter the second set

            int Nb;
            printf("Enter the number of elements in the second set : \n");
            scanf("%d", &Nb);
            printf("Enter the second set of numbers : \n");
            int b[Nb], bn[10] = {0};
            for( i = 0; i < Nb; i++)
            {
                scanf("%d", &b[i]);
            }

                // Same method here for the first set

                printf("The second set : \n");
                for(j = 0; j < 10; j++)
                {
                    for(i = 0; i < Nb; i++)
                    {
                        if(b[i] == j)
                        {
                            bn[j]++;
                        }
                    }

                    printf("%d %d \n", j , bn[j]);


                }
                        // Algorithm for the union and intersection set based on the other array

                        printf("The union set : \n");
                        for(i = 0; i < 10; i++ )
                        {
                            if(bn[i] >= 1 || an[i] >= 1)
                            {
                                printf("%d \t",i );
                            }
                        }
                            printf("\n");
                                printf("The intersection set : \n");
                                for(i = 0; i < 10; i++)
                                {
                                    if(bn[i] >= 1 && an[i] >= 1)
                                    {
                                        printf("%d \t", i);
                                    }
                                }

                                    return 0;
                                }
