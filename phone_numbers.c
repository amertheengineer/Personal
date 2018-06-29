/*
    Amer Abdelaziz
    U25449742

        This program takes in a file name from a user and
        converts that characters in it to numbers
        using the phone keyboard as a reference
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void translate(char *word, char *phone_number);

int main()
{
    /* Declaring the files */

    FILE *infile,*outfile;
    char words[8];
    char nameOfInfile[30];
    char nameOfOutfile[30];
    char phoneNo[8];

    printf("Enter file name: \n");
    scanf("%s",nameOfInfile);

    /* Creating the .cvt file */
    strcpy(nameOfOutfile,nameOfInfile);
    strcat(nameOfOutfile,".cvt");
    infile = fopen(nameOfInfile, "r");
    outfile = fopen(nameOfOutfile, "w");

    /* Conditions and algorithms */
        if (infile == NULL)
        printf("File DNE!\n");

            else
            {
                while (!feof(infile))
                {
                    fscanf(infile, "%s",words);
                    /* function call */
                    translate(words,phoneNo);
                    fprintf(outfile,"%s\n",phoneNo);
                }
            }

            /* Closing the files*/
            fclose(infile);

            fclose(outfile);


    return 0;
}
/* Treating the word as a string of characters
    and writing the function using a for loop
*/
void translate(char *word, char *phone_number)
{

                /* Pointing the char p to word and conditioning
                   i loops as well
                */
        char *p;
        int result;
        int i;

        for( p = word, i = 0; *p != '/0', i < strlen(word); p++, i++)
        {
            if( *p >= 'A' && *p <= 'C')
            {
                    result = 50;
            }
            if(*p >= 'D' && *p <= 'F')
            {
                result = 51;
            }
            if(*p >= 'G' && *p <= 'I')
            {
                result = 52;
            }
            if(*p >= 'J' &&*p <= 'L')
            {
                    result = 53;
            }
            if(*p >= 'M' && *p <= 'O')
            {
                result = 54;
            }
            if(*p >= 'P' && *p <= 'S')
            {
               result = 55;
            }
            if(*p >= 'T' && *p <= 'V')
            {
                result = 56;
            }
            if(*p >= 'W' && *p <= 'Y')
            {
                result = 57;
            }
            /* Storing the array*/

                *(phone_number + i) = result;


        }
    *(phone_number + i ) = '\0';


}
