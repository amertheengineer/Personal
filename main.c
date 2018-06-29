/*

Amer Abdelaziz
U25449742

selection_sort.c, project 5, Program Design


 */
#include <stdio.h>
#define N 5


void selection_sort(int a[], int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);
int main(void)
{   int i;
    int a[N];

  printf("Enter %d numbers to be sorted: ", N);

    for (i = 0; i < N; i++)

    scanf("%d", &a[i]);

        selection_sort(a, N);
        printf("In sorted order:");

            for (i = 0; i < N; i++)

                printf(" %d", a[i]);
                printf("\n");


  return 0;

  }
  // I the selection_sort function, we call both find_largest and swap functions (and use recursion)

void selection_sort(int *a, int n)
{

    int *max;
    int *last;

    last = a+n-1;

    if (n == 1)
    return;

            max = find_largest(a,n);
            swap(last,max);
            selection_sort(a, n-1);

  }

  // The find_largest function returns a max value from any given data

int *find_largest(int *a, int n)
    {
            int *p;
            int *amax = a;

            for(p = a+1;p < a+n;p++)
                {

                    if(*p > *amax)
                    {
                        amax = p ;

                    }
                }

                    return amax;

    }

    // The swap function swaps two variables

void swap(int *p, int *q)

    {

            int temp;

            temp = *q;
            *q = *p;
            *p = temp;


    }
