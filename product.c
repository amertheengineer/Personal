/*
    Amer Abdelaziz
    U25449742

    This program sorts out the volume of units sold in
    order form a file

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Declaring the struct */
struct product{

        char name[1000];
        double price;
        double tot_sold;
        double volume;


    };
void selection_sort(struct product products[] , int n);


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

        selection_sort( products,i);
        FILE *outfile = fopen("sorted_products.txt","w");
        int j;
        fprintf(outfile,"Name\tPrice\tUnits\tVolume\n");
        for( j = 0; j < i; j++)
           {
               fprintf(outfile,"%s \t %.2lf \t %.2lf \t %.2lf \n",products[j].name,products[j].price,products[j].tot_sold,products[j].volume);
           }



        fclose(file);
        fclose(outfile);



    return 0;
}
/* Selection sort from class modified for structs */
void selection_sort(struct product products[] , int n)
{
int i, largest = 0;
double temp_volume, temp_price, temp_total;
char temp[20];
if (n == 1)
    return;

for (i = 1; i < n; i++)
{

    if (products[i].volume > products[largest].volume)
    largest = i;

}


if (largest < n-1)
{
temp_volume = products[n-1].volume;
products[n-1].volume = products[largest].volume;
products[largest].volume = temp_volume;

temp_price = products[n-1].price;
products[n-1].price = products[largest].price;
products[largest].price = temp_price;

temp_total = products[n-1].tot_sold;
products[n-1].tot_sold= products[largest].tot_sold;
products[largest].tot_sold = temp_total;

strcpy(temp ,products[n-1].name);
strcpy(products[n-1].name, products[largest].name);
strcpy(products[largest].name ,temp);



}

selection_sort(products, n - 1);
}
