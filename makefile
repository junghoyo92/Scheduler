scheduler:	scheduler.o display.o
	gcc -o scheduler scheduler.o display.o

scheduler.0: scheduler.c scheduler.h display.h
	gcc -c scheduler.c
	
display.o: display.c display.h scheduler.h
	gcc -c display.c

clean:
		rm -f *.o scheduler
