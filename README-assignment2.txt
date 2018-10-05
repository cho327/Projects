Files for assignment2 go here.
Sorting.c
minsort.c
bubblesort.c
insertionsort.c
quicksort.c
mergesort.c
Makefile

Sorting.c is a program that brings together all the sorting files by using the getopt function. 
It does this from the usage of header files that are made for each sorting code. 
Using getopt, it ttakes in user input that specifies which algorithm it wants to use and whether it wants to modify statistics or how much the user wishes to see of the sorted array. 
my sorting.c has two modules that are called printsorted, and copyarray. Printsorted prints the statistics of the array and the sorted array up to the number that the user specified.
copy array copies the random array so that i won't have to modify rand_array everytime.

each one of the sorting files uses a different sorting algorithm to sort an array of random integers up to 16777215.
My makefile compiles all of the sorting files and creates an executable called sorting. clean then clenas out all created files.
