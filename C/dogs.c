/*
    Amer Abdelaziz
    U25449742

        This code keeps track of a list dogs
        given their data including the dog's name,
        breed, number, and owner's last name

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NAME_LEN 30

// From project file

struct dog
{
    int number;
    char dog_name[NAME_LEN+1];
    char owner_last_name[NAME_LEN+1];
    char breed[NAME_LEN+1];
    struct dog *next;
};

struct dog *append(struct dog *list);
void search(struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
int read_line(char str[], int n);

int main()
{

    char code;
    struct dog *dog_list = NULL;

    printf("Operation Code: a for appending to the list, s for finding a dog"
  ", p for printing the list; q for quit.\n");
  for(;;)
  {
      printf("Enter operation code: ");
      scanf(" %c", &code);
      while (getchar() != '\n');
        /* skips to end of line */
        switch (code)
        {
              case 'a': dog_list = append(dog_list);
              break;
              case 's': search(dog_list);
              break;
              case 'p': print(dog_list);
              break;
              case 'q': clear(dog_list);
              return 0;
              default:
              printf("Illegal code\n");
          }

          printf("\n");
          }

  }
struct dog *append(struct dog *list)
{

    struct dog *new_dog, *temp;
    int num = 0, count = 1;

    printf("Enter dog's number : \n");
    scanf("%d", &num);

    /* If the list is initially empty */

    if(list == NULL)
    {
        new_dog = (struct dog * )malloc(sizeof(struct dog));
        new_dog ->number = num;
        printf("Enter dog's name : \n");
        scanf("%s", new_dog->dog_name);
        printf("Enter dog's breed : \n");
        scanf("%s", new_dog ->breed);
        printf("Enter the dog's last name : \n");
        scanf("%s", new_dog->owner_last_name);
        new_dog ->next = NULL;
        list = new_dog;
    }
        /* Adding a dog into a list */
        else
        {
            temp = list;
            while(count)
            {

                    if(temp->number == num)
                    {
                        printf("Dog exists!\n");
                        count = 0;

                    }
                        else if(temp ->next == NULL)
                        {
                            new_dog = (struct dog *)malloc(sizeof(struct dog));
                            new_dog ->number = num;
                            printf("Enter dog's name : \n");
                            scanf("%s", &new_dog->dog_name);
                            printf("Enter dog's breed : \n");
                            scanf("%s", &new_dog ->breed);
                            printf("Enter the dog's last name : \n");
                            scanf("%s", &new_dog->owner_last_name);

                            /* Fitting the new dog into the list */

                            new_dog->next = NULL;
                            temp ->next = new_dog;
                            count = 0;

                        }
                            else
                                temp = temp->next;
            }

        }
    return list;

}


/* Search function looks up by name */

void search (struct dog *list)
{
struct dog *temp;
int found = 0;
char input[NAME_LEN+1];

printf("Enter dog's name : \n");
scanf("%s",&input);

temp = list;
while(temp != NULL)
{

    if(!strcmp(temp->dog_name,input))
    {
            printf("Dog found!");
            found++;
            break;
    }
        temp = temp->next;
}

if(found == 0)
{
    printf("Dog not found!\n");
}


}

/* Print function loops through the list and prints the name and number */

void print(struct dog *list)
{
    struct dog *p1 = list;
    printf("Dog's name: \tDog Number: \t \n");

    do
    {
        printf("%s \t", p1->dog_name);
        printf("%d \n", p1->number);
        p1 = p1->next;
    }while(p1!=NULL);


}
/* Deallocaing memory by freeing it */
void clear(struct dog *list)
{
    struct dog *p;
    while(list != NULL)
    {
        p = list;
        list = list ->next;
        if(p != NULL)
        {
            free(p);
        }
    }

}
/* read_line function from project file */
int read_line(char str[], int n) {
    int ch, i = 0;
  while (isspace(ch = getchar()))     ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n')
    {
        if (i < n)
        str[i++] = ch;
     }
         str[i] = '\0';
         return i;
  }
