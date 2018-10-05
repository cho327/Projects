OLD = true
MASK = 0x00ffffff
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c99
OBJECTS = minsort.o bubblesort.o insertionsort.o quicksort.o mergesort.o sorting.o #bv.o

.PHONY: all
all : sorting

sorting : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o sorting

sorting.o : sorting.c
	$(CC) $(CFLAGS) -c sorting.c

minsort.o : minsort.c
	$(CC) $(CFLAGS) -c minsort.c

bubblesort.o : bubblesort.c
	$(CC) $(CFLAGS) -c bubblesort.c

insertionsort.o : insertionsort.c
	$(CC) $(CFLAGS) -c insertionsort.c

quicksort.o : quicksort.c
	$(CC) $(CFLAGS) -c quicksort.c

mergesort.o : mergesort.c
	$(CC) $(CFLAGS) -c mergesort.c

clean:
	rm -f $(OBJECTS) sorting	
