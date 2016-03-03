/*
This program was inspired by a prompt on Reddit, specifically from r/Programming Prompts.  
The program will calculate the day of the week of any inputted date, within bounds from March 1, 1900 to December 31, 2099.  
The date should be input as a command line argument, in the format MM DD YYYY, following the command ./day immediately.
The program will determine the day of the week of the given date and print it to the screen, then exit.
*/

#include <stdio.h>
#include <stdlib.h>


//prototypes
int printerr(void);


int main(int argc, char* argv[])
{
//input of inappropriate args, redirect user
    //not enough arguments:
    if(argc != 4)
    {
        printerr();
        return 1;
    }
    //argv[1] not a month
    int month = atoi(argv[1]);
    if(month < 1 || month > 12)
    {
        printerr();
        return 2;
    }
    //if argv[2] not a day
    int date = atoi(argv[2]);
    if(date < 1 || date > 31)
    {
        printerr();
        return 3;
    }
    //reject if input a day value that doesn't exist in that particular month
    //April, June, September, and November
    if((month == 4 || month == 6 || month == 9 || month == 11) && date > 30)
    {
        printerr();
        return 4;
    }
    //February
    int year = atoi(argv[3]);
    int leap = year % 4;
    if((month == 2 && leap !=0 && date > 28) || (month == 2 && leap == 0 && date > 29))
    {
        printerr();
        return 5;
    }
    //limit years to 1900 to 2100
    if(year < 1900 || year >= 2100)
    {
        printerr();
        return 6;
    }
    //remove cases before March 1900
    if(year == 1900 && month < 3)
    {
        printerr();
        return 7;
    }

//algorithm to calculate day of week
int y = year - 1900;
int leaps = y / 4;
int leap2 = y % 4;

const char *week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char *mos[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int totals[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int a = y * 365 + leaps;

        if(month < 3 && leap2 == 0)
            {
                int b = a - 1 + totals[month - 1] + date;
                int val = b % 7; 
                printf("The date %s %i, %i falls on %s.\n", mos[month - 1], date, year, week[val]);
                return 0;
            }
            else if(month < 3 && leap2 != 0)
            {
                int b = a + totals[month - 1] + date;
                int val = b % 7;
                printf("The date %s %i, %i falls on %s.\n", mos[month - 1], date, year, week[val]);
                return 0;
            }
            else
            {
                int b = a + totals[month - 1] + date;
                int val = b % 7;
                printf("The date %s %i, %i falls on %s.\n", mos[month - 1], date, year, week[val]);
            }
}

//error printout function
int printerr() 
{
    printf("Please try again with a valid date, using this format: './day MM DD YYYY'!\n");
    return 0;
} 
