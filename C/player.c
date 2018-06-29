
#include "player.h"
/*
    From class except for the delete function

*/
struct player *append_to_list(struct player *roster){
   struct player *x, *temp;
   char first[NAME_LEN+1], last[NAME_LEN+1];
   int num, found;
   x = roster;
   printf("Enter the first name of the player: ");
   scanf("%s", first);
   printf("Enter the last name of the player: ");
   scanf("%s", last);
   printf("Enter the number of the player: ");
   scanf("%i", &num);
   found = 0;
   while(x != NULL){
       if(x->number == num)
       found = 1;
       x = x->next;
   }
   if(found){
       printf("Player with this number already exists...\n");
       return roster;
   }
   else{
       temp = (struct player *)malloc(sizeof(struct player));
       strcpy(temp->first_name, first);
       strcpy(temp->last_name, last);
       temp->number = num;
       temp->next = NULL;
       if(roster == NULL){
           return temp;
       }
       else{
           x = roster;
           while(x->next != NULL)
           x = x->next;
           x->next = temp;
           return roster;
       }
   }
}
void find_player(struct player *roster){
   int num;
   printf("Enter the number of the player to search for: ");
   scanf("%i", &num);
   while(roster != NULL){
       if(roster->number == num){
           printf("%s %s", roster->last_name, roster->first_name);
           break;
       }
       roster = roster->next;
   }
   if(roster == NULL)
       printf("The player does not exist...\n");
}
void printList(struct player *roster){
   while(roster != NULL){
       printf("%s %s %i\n", roster->last_name, roster->first_name, roster->number);
       roster = roster->next;
   }
}
void clearList(struct player *roster){
   struct player *x;
   while(roster != NULL){
       x = roster;
       roster = roster->next;
       free(x);
   }
}

/*
    This function deletes a player from the roster

*/
struct player* delete_from_list(struct player*roster) {
   printf("Enter player number to be deleted:\n");
       int pnum = 0;
       scanf("%d",&pnum);
       struct player *x, *prev = NULL, *cur = NULL;
       x = roster;
       while(x != NULL)
            {

               if(x->number == pnum)
                {
                   if(prev == NULL)
                        {

                            x = x->next;

                        }
                        else
                           {
                               prev->next = x->next;
                           }
                   cur = x;
                   break;
               }
               prev = x;
               x = x->next;

           }

       if(cur == NULL)
           printf("Player not found: id = %d",pnum);
       else
           printf("Deleted Player with id = %d",pnum);
// return roster or deleted player - change it as per ur need
       return cur;
}

