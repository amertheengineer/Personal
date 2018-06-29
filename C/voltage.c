#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Amer Abdelaziz
    U25449742

        This program prints out a table
        that contains a time and a voltage
        where the voltage is a function of time

*/
int main()
{
    printf("Time \t Voltage\n");

    double time;

    for(time = 0; time <1; time+=0.5)
    {
        printf("%.2lf \t %.2lf \n", time,0.5*sin(2*time));

    }
    for(time = 1; time <= 10; time+=.5)
    {
        printf("%.2lf \t %.2lf \n", time,sin(time));
    }
    for(time > 10;time <=12;time+=0.5)
    {
        printf("%.2lf \t %.2lf \n",time, sin(10));
    }
    return 0;
}
