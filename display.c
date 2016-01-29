#define __USE_XOPEN
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "scheduler.h"

/* Function used to display the schedule */

void DisplayEvents(Schedule *schedule)
{
    int i;

    printf("\nSchedule:\n");
    for(i=0;  i<schedule->numEvents;  i++)
    {
        DisplayEvent(schedule->events[i]);
    }

    printf("\n");
}

void DisplayEvent(Event * event)
{
	printf("Name: %s \n", event->name);
	printf("Date: %s \n", event->date);
	printf("Start Time: %s \n", event->start);
	printf("End Time: %s \n", event->end);
}
