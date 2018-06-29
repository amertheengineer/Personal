/*
    Amer Abdelaziz
    U25449742

        This code creates a roster and allows to
        append, find, clear, and print out
        a roster
        Code from class

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NAMELEN 30
#define TRUE 1
#include "player.h"


int main()
{



    char code;
    struct player *team_roster = NULL;
    printf("Operation Code: a for appending to the roster, f for finding a player"
    ", p for printing the roster; q for quit.\n");
for(;;)
    {

    /* Attaining the code from the user*/

    printf("Enter Operation Code: \n");
    scanf("%c", &code);
    while(getchar() != '\n');
    switch (code)
    {
        case 'a': team_roster = append_to_list(team_roster);
        break;
        case 'f': find_player(team_roster);
        break;
        case 'p': printList(team_roster);
        break;
        case 'q': clearList(team_roster);
        return 0;
        default: printf("Illegal code\n");
    }
     printf("\n");
    }
    }




