/*
    Amer Abdelaziz
    U25449742

        This code creates a roster and allows to
        append, find, clear, and print out
        a roster

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define NAMELEN 30

struct player *append_to_list(struct player *roster);
void find_player(struct player *roster);
void printList(struct player *roster);
void clearList(struct player *roster);


    struct player{

            int num;
            char f_name[NAMELEN + 1];
            char l_name[NAMELEN + 1];
            struct player *next;

    };

int main()
{
    for(;;)
    {


    char code;
    struct player *team_roster = NULL;
    printf("Operation Code: a for appending to the roster, f for finding a player"
    ", p for printing the roster; q for quit.\n");


    /* Attaining the code from the user*/

    printf("Enter Operation Code: \n");
    scanf("%c", &code);
    while(getchar() != '\n');
    switch(code)
    {
        case 'a' : team_roster = append_to_list(team_roster);
        break;
        case 'f' : find_player(team_roster);
        break;
        case 'p' : printList(team_roster);
        break;
        case 'q' : clearList(team_roster);
        return 0;
        default: printf("Illegal Code ! \n");

    }
    /* This struct creates a database for each player with
        the use of their first name, last name, and jersey number
        *******
    */
    struct player *append_to_list(struct player *roster)
        {
            struct player *temp, *uk;
            char f[NAMELEN+1], l[NAMELEN+1];
            int num,found;
            temp = roster;
            printf("Enter player's first name : \n");
            scanf("%s",&f);
            printf("Enter player's last name: \n");
            scanf("%s",&l);
            printf("Enter player's jersey number: \n");
            scanf("%d",num);

            while(temp != NULL)
            {

                if((*temp).num == num)
                {
                    found = 1;
                    temp = (*temp).next;
                }
            }
                if(found)
                {
                    printf("Player's jersey number exists!");
                    return roster;
                }

                    else
                        {
                            uk = (struct player*) malloc(sizeof(struct player));

                            strcpy((*uk).f_name,f);
                            strcpy((*uk).l_name,l);
                            (*uk).num = num;
                            (*uk).next = NULL;
                            if(roster == NULL)
                            {

                                return uk;

                            }
                                else
                                    {
                                        temp = roster;
                                            while((*temp).next != NULL)


                                                temp = (*temp).next;
                                                (*temp).next = temp;
                                                return roster;


                                    }
                        }
        }

    }
}
// This function finds a player by searching through the num and roster.num
void find_player(struct player *roster)
{
    int num;
    printf("Enter player's number to search for \n");
    scanf("%s",&num);

    while(roster != NULL)
    {
        if((*roster).num == num)
        {
            printf("Player exists! \n");
            printf("%s %s",(*roster).l_name,(*roster).f_name);
            break;
        }
        roster = (*roster).next;
        if((*roster).num == NULL)
        {

            printf("Player doesn't exist! \n");
        }

    }

}
// This function justs prints out the data for each player
void printList(struct player *roster)
{
    while(roster != NULL)
    {
        printf("Player's data: \n");
        printf("%s %s %d", (*roster).f_name,(*roster).l_name,(*roster).num);
        roster = (*roster).next;
    }


}
// This function frees up (deallocates) the space for the name by the free function
void clearList(struct player *roster)
{
    struct player *temp;
    while(roster != NULL )
    {
        temp = roster;
        roster = (*roster).next;
        free(temp);

    }


}
// Read_Line function from class
int read_line(char str[], int n)
{
int ch, i = 0;

while (isspace(ch = getchar()))
;
str[i++] = ch;
while ((ch = getchar()) != '\n') {
if (i < n)
str[i++] = ch;
}
str[i] = '\0';
return i;
}

