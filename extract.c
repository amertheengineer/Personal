/*
    Amer Abdelaziz
    U25449742

        This code prompts the user for a URL address
        and the code takes in the address and a URL
        is created beginning with www. and ending with .edu

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void extract(char *s1,char *s2);
int read_line(char *str, int n);
int main()
{
    printf("Enter a URL \n");
    char input[1000], output[1000];
    read_line(input,1000);
    extract(input, output);
    printf("The output is : %s\n", output);

    return 0;
}
void extract(char *s1, char *s2)
{
    int i = 0, j = 0;
    int start_index = 0, end_index = 0;
    for(i = 0 ; i <= strlen(s1); i++)
    {


        if(*(s1+i) == 'w' && *(s1+ i + 1) == 'w' && *(s1 + i + 2) == 'w')
        {
            start_index = i;
        }
            if(*(s1+i) == 'e' && *(s1+ i + 1) == 'd' && *(s1 + i + 2) == 'u')
            {
                end_index = i + 2;

            }




    }
            if(start_index == 0 && end_index == 0)
                {
                    printf("Web address starting with www. and ending with .edu not found");
                }

                    else
                    {
                        for(start_index; start_index <= end_index; start_index++)
                        {
                            *(s2+j) = *(s1+start_index);
                            j++;
                        }
                    }


    *(s2+j) = '\0';


}
// read_line function from notes
int read_line(char *str, int n)
 {
int ch, i = 0;
 while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            *str++= ch;
            i++;
        }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}
