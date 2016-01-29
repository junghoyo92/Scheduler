#define __USE_XOPEN
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#include "scheduler.h"

/* 
 *	Name:    	<Hoyoung Jung>
 *	Project: 	Project 3
 * 	Title:	 	Scheduling Program
 *	Due Date:	12-12-13
 */

/* Main Function */
int main()
{
	int command;
	bool valid = false;
	bool valid2 = true;
	int i;
	int Num = 0;
	Event * event;
	event = malloc(sizeof(Event));
	
	do
	{
		do
		{
			printf("1 - Insert a new event\n"
					"2 - Display all events\n"
					"3 - Now?\n"
					"4 - Delete expired\n"
					"0 - Exit\n"
					"Please select an option: ");
			scanf("%i", &command);
			if(command <= 4 && command >= 0)
			{
				valid = true;
			}
			else
			{
				printf("Not a valid option. Please select a command\n");
				valid = false;
			}
		}while(!valid);
	
		if(valid)
		{
			switch(command)
			{
				case NewEvent:
					event[Num] = InputEvent();
					Num ++;
					break;
				case Display:
					DisplayEvents();
                   		        Num++;
					break;
				case Now:
					break;
				case DeleteExpired:
					break;
				case Exit:
					return 0;
					break;
			}
		}
	
		if(feof(stdin))
		        return 0;
    }while(!valid2);
}

/* Struct used to prompt and obtain event data from user */
struct Event InputEvent()
{
	char name;
	int max = 50;
	time_t date;
	time_t start;
	time_t end;
	
	struct Event e1;
	
	name = InputString("Name of Event: ", max);
	date = InputDate("Input Date: ");
	start = InputTime("Input Start Time: ", date);
	end = InputTime("Input End Time: ", date);
	
	return e1;
	
	struct tm
	{
	  int tm_sec;			/* Seconds.	[0-60] (1 leap second) */
	  int tm_min;			/* Minutes.	[0-59] */
	  int tm_hour;			/* Hours.	[0-23] */
	  int tm_mday;			/* Day.		[1-31] */
	  int tm_mon;			/* Month.	[0-11] */
	  int tm_year;			/* Year	- 1900.  */
	  int tm_wday;			/* Day of week.	[0-6] */
	  int tm_yday;			/* Days in year.[0-365]	*/
	  int tm_isdst;			/* DST.		[-1/0/1]*/
	};
}



/* Function used to get a string */
char InputString(char *str, int max)
{
	char buffer[50];
    struct tm string;
	
	/* Get a line of up to 50 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any stray newlines from the buffer */
    while (buffer[0] == '\n')
        fgets(buffer, sizeof(buffer), stdin);
    
    /* Remove any \n we may have input */
    if(strlen(buffer) > 0)
        buffer[strlen(buffer)-1] = '\0';
        
    /* Copy up to max characters to our string */
    strncpy(str, buffer, max);
    str[max-1] = '\0';
    
    return mktime(&string);
    
}

/* Function used to obtain an inputed date */
time_t InputDate(char *prompt)
{
    char buffer[100];
    char *result;
    struct tm date;

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        result = strptime(buffer, "%m/%d/%Y", &date);

    } while(result == NULL);

    return mktime(&date);
}

/* Function used to obtain an inputed time */
time_t InputTime(char *prompt, time_t date)
{
    char buffer[100];
    char *result;
    struct tm time;

    time = *localtime(&date);

    do
    {
        printf("%s", prompt);

        /* Get a line of up to 100 characters */
        fgets(buffer, sizeof(buffer), stdin);

        /* Remove any \n we may have input */
        if(strlen(buffer) > 0)
            buffer[strlen(buffer)-1] = '\0';

        result = strptime(buffer, "%I:%M%p", &time);

    } while(result == NULL);

    return mktime(&time);
}
