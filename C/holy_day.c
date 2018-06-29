/*

    Amer Abdelaziz
    U25449742
    This program gathers information from the user including the day the professor assigns the HW and
    the number of days till the HW is due (D).
    If the due date is on a religious holy day such as Friday, Saturday or Sunday, it'll add enough days to reach
    the following Monday and assign a new D value

*/
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int D, day, duedate;
    int incseven = duedate+ 7;


    printf("Enter the day in which your HW was assigned: \n");

    scanf("%d",&day);

    // Condition..

    if(day >= 0 && day <= 6)
    {

        // Attaining the D value from the user!

            printf("Enter the number of days till the due date: \n");
            scanf("%d", &D);

            duedate = D + day;

            // Doing the case based off of the due date.

        switch(duedate)
        {

            // Sunday!

                case 0:
                case 7:
                case 14:
                case 21:
                case 28:
                    printf("Your due date was Sunday! \n");
                    D+=1;
                    printf("%d days will be added! \n", 1);
                    printf("Your corrected D value would be : %d \n", D);
                     printf("Your new due date will be Monday!");
                        break;

             // Monday!

                case 1:
                case 8:
                case 15:
                case 22:
                case 29:
                    printf("Your due date is Monday! \n");
                        break;
             // Tuesday!

                case 2:
                case 9:
                case 16:
                case 23:
                case 30:
                    printf("Your due date is Tuesday! \n");
                        break;

             // Wednesday!

                case 3:
                case 10 :
                case 17:
                case 24:
                case 31:
                    printf("Your due date is Wednesday! \n");
                        break;

             // Thursday!

                case 4:
                case 11:
                case 18:
                case 25:
                case 32:
                    printf("Your due date is Thursday! \n");
                        break;

             // Friday with 3 days being added has a new due date (Monday) and a new D value!

                case 5:
                case 12:
                case 19:
                case 26:
                case 33:
                        printf("Your due date was Friday! \n");
                        D+=3;
                         printf("%d days will be added! \n", 3);

                        printf("Your corrected D value would be : %d \n", D);
                        printf("Your new due date will be Monday!");
                        break;

               // Saturday with 2 days being added has a new date (Monday) and a new D value!

                case 6:
                case 13:
                case 20:
                case 27:
                case 34:
                        printf("Your due date was Saturday! \n");
                        D+=2;
                        printf("%d days will be added! \n", 2);
                        printf("Your corrected D value would be : %d \n", D);
                         printf("Your new due date will be Monday!");
                        break;


                default :

                        break;



        }

    }

    // If the user inputs a value less than 0 or greater than 6!

        else
            {

                printf("Error, enter a number grater than 0 and less than 6!");

            }



    return 0;
}
