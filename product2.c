#include <stdio.h>
#include <stdlib.h>

    /* Declaring the struct */
struct product{

        char name[1000];
        double price;
        double tot_sold;
        double volume;


    };
void find_product(struct product products[], int n, char *name);

int main(int argc, char *argv[])
{

/* Declaring the struct array */

    struct product products[20];

    FILE *file = fopen("amer.txt","r");

    if(file == NULL)
    {
        printf("Error! file DNE");
    }

        char name[20];
        int i = 0;
    /* The while loop keeps looping till it reaches a line that has no data*/

        while(fscanf(file, "%s %lf %lf", &products[i].name, &products[i].price, &products[i].tot_sold) > 0)
        {

            products[i].volume = products[i].price*products[i].tot_sold;
            i++;

        }
        find_product(products,i,argv[1]);



    return 0;
}

/* This function checks whether the string from the argument matches the data from
    the struct and displays it's contents*/
void find_product(struct product products[], int n, char *name)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(strcmp(products[i].name,name) == 0)
        {
            printf("Name: %s\nUnit price: %.2lf\nNumber of pounds sold: %.2lf\nSale volume: %.2lf\n"
                   ,products[i].name,products[i].price,products[i].tot_sold,products[i].volume );
        }
    }
}
