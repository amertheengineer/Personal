
/*
    Amer Abdelaziz
    U25449742

    This program sorts its command line arguments of 10 numbers
    which are integers and prints out either is descending or ascending order


*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
#define ERR -1

// Calling the functions

void selection_sort_as(int a[], int n);
void selection_sort_ds(int a[], int n);
int  ordred(const char argv[]);
void changearray(int *arr, char *argv[], int n);

int main(int argc, char *argv[])
{

    int input[MAX];

    /* Condition whether to ascend or descend

        Also changing the array form a string into an

        integer array

            */

    if(ordred(argv[1]) != ERR)
    {
        changearray(input, argv, argc);


    if(ordred(argv[1]) == TRUE)
        {
            selection_sort_as(input,MAX);

        }
            else
            {
                    selection_sort_ds(input,MAX);

            }

        }
        else
        {
            printf("Error in the input!");

        }

                int z;
                for(z = 0; z < MAX; z++)
                {

                    printf("%d",input[z]);

                }

    return 0;
}
/*
    Selection_sort function from class
    with a minor change to the ascending
    It checks if numbers are larger and replaces it with a max value

*/
void selection_sort_as(int a[], int n)
{

    int z, max = 0, temp;

  if (n == 1)
    return;

  for (z = 1; z < n; z++)
  {
    if (a[z] > a[max])
      max = z;
  }

  if (max < n - 1)
    {

            temp = a[n-1];

            a[n-1] = a[max];

            a[max] = temp;

    }

  selection_sort_as(a, n - 1);
}

/*
    Selection_sort function from class
    with a minor change to the descending
    It checks if numbers are smaller and replaces it with a min value


    */
void selection_sort_ds(int a[], int n)
{

    int min, temp, z;

    if(n == 1)
        return;


  for (z = 1; z < n; z++)
  {
       if (a[z] < a[min])
    min = z;

  }


  if (min < n - 1)
   {

       temp = a[n-1];

       a[n-1] = a[min];

       a[min] = temp;
  }

    selection_sort_ds(a, n - 1);

}
/*
    This function checks whether to ascend or descend the

    arrays based off of the input

    */

int ordred(const char *argv)
{
    if(strcmp(argv,"-d") == 0)
    {
        return FALSE;

    }
        else if(strcmp(argv,"-a") == 0)
        {
            return TRUE;

        }

                else
                {

                    return ERR;
                }
}

/*
    This function changes the array from a string
    into an integer array

*/

void changearray(int *arr, char *argv[], int n)
{
    int i;

    for(i = 2; i < n; i++)
    {

        *arr++ = atoi(argv[i]);
    }


}

