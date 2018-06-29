/*
    Amer Abdelaziz
    U25449742

    This program scans a sentence from a user and
    determines the frequency of a word in the sentence

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define WMAX 50
#define LMAX 1000



int read_line(char *str, int n);
int pos(char *word, char *sen[], int n);
int is(char *word, char *sen[], int n);

int main()
{
    /* Declarations */
    int s;
    char input[LMAX];
    int count[LMAX] = {0};
    int position, totalwords = 0;
    char *word;
    char *typ[WMAX];
    position = TRUE;
    count[0] = 1;

    printf("Enter a word: \n");
    s = read_line(input,LMAX);
    word = strtok(input, " .,-");
    typ[0] = word;
    count[0] = TRUE;
    totalwords++;

    /* Breaking the sentence into words using strtok  */
    /* We also increment the values in the array count*/

        word = strtok(NULL, " .,-");
        while(word != NULL)
        {
            if(is(input,typ,totalwords)==TRUE)
            {
                int p = pos(input,typ,s);
                count[p]++;
            }
                else
                {
                    typ[position] = word;
                    count[position]++;
                    totalwords++;
                    position++;
                }

            word = strtok(NULL," .,-");
        }
        /* Printing the frequency and word*/
        int i;
        printf("Word\t Frequency\n");
        for( i = 0; i < totalwords; i++)
        {
            printf("%s\t %d \n", typ[i], count[i]);
        }
        printf("\n");

    return 0;
}

/* read_line function from class */
int read_line(char *str, int n) {
     int ch; int i = 0;

    while ((ch = getchar()) != '\n')
        {
            if (i < n)
                {
                    *str++= ch;
                    i++;
                }
        }
  *str = '\0';
  /* terminates string */
  return i;
    /* number of characters stored */
  }

// This function returns the position of the word in the sentence

int pos(char *s, char *sen[], int n)
{
    int i;
    for(i = 0; sen[i] != '\0' ; i++)
    {
        if(strcmp(s,sen[i]) == 0)
        {
            return i;
        }
        i++;
    }
    return TRUE;
}
// This function determines whether the sentence contains the word it's searching for
int is(char *s, char *sen[],int n)
{
    int z = 0;

    for(z = 0; sen[z] != '\0'; z++)
    {
            if(strcmp(s,sen) == 0)
            {
                return TRUE;
            }

    }

}

