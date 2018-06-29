/*
    Amer Abdelaziz
    U25449742

    This program prompts the user to enter a
    sentence and it outputs all caps and gets
    rid of the punctuation

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    // Prompting the user
    printf("Enter a sentence : \n");

    char input, output;
// The do while loop will keep looping till the the user presses enter
    do{

        input= getchar();

        output = toupper(input);

        // Checking if the the output is all alpha or not

       if(isalpha(output))
       {
           printf("%c",output);
       }

            else if(output == ' ')
            {
                printf("%c", output);
            }

    }while(input != '\n');


    return 0;
}
