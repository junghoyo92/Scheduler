#ifndef SCHEDULER_H
#define SCHEDULER_H

/* Define Cases for Switch Machine */
#define Exit 0
#define NewEvent 1
#define Display 2
#define Now 3
#define DeleteExpired 4

typedef struct Event
{
	char name[50];
	char date[10];
	char start[10];
	char end[10];
}Event;

typedef struct Schedule
{
	char events[50];
	int numEvents;
}Schedule;
	

/* Declaration of Functions */
struct Event InputEvent();
char InputString(char *str, int max);
time_t InputDate(char *prompt);
time_t InputTime(char *prompt, time_t date);

#endif
